#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string.h>
#include <glib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <dbus/dbus.h>
#include <dbus/dbus-glib.h>

#include "skype-service.h"
#include "skype-service-object-glue.h"


static DBusGConnection *g_dbus_conn = NULL;
static DBusGProxy *proxy_send = NULL;
static SkypeService *service_object = NULL;

ros::Publisher skype_pub;

#define DBUS_MPRIS_TIMEOUT 300 // Milliseconds

void skype_setup_notify_methods(gboolean do_register/*register or unregister*/);
void clean_up(void);

DBusGConnection *dbus_player_connect_to_dbus() {
    // Connect to GLib/DBus 
    GError *error = NULL;

    if (!g_dbus_conn) {
        g_dbus_conn = dbus_g_bus_get(DBUS_BUS_SESSION, &error);

        if (!g_dbus_conn) {
            g_print("dbus_player_connect_to_dbus: Cannot connect to DBus: %s\n", error ? error->message : "");

            if (error)
                g_error_free(error);

            return NULL;
        }
    }
    return g_dbus_conn;
}

gchar *skype_send_message(gchar *command) { 
    // Send message to Skype 

    // Connect
    DBusGConnection *dbus_conn = dbus_player_connect_to_dbus();

    // Create proxy
	GError *error = NULL;
    if (!proxy_send) {
        proxy_send = dbus_g_proxy_new_for_name(dbus_conn,
                                           "com.Skype.API",
                                           "/com/Skype",
                                           "com.Skype.API");
    }

    if (!proxy_send) {
        g_printerr("Cannot create proxy_send.\n");
        return NULL;
    }

    // Send message and get return value
	gchar *str = NULL;
	error = NULL;
	if (!dbus_g_proxy_call(proxy_send, "Invoke", &error,
				G_TYPE_STRING, command,
				G_TYPE_INVALID,
				G_TYPE_STRING, &str,
				G_TYPE_INVALID)) {

        if (error) {
            g_printerr("Failed to make DBus call: %s.\n", error->message);
            g_error_free(error);
        }
        else {
            g_printerr("Failed to make DBus call.\n");
        }

		return NULL;
	}

    // The caller should g_free() this value
    return str;
}

void skype_setup_notify_methods(gboolean do_register) {
    // Connect to DBus
    DBusGConnection *dbus_conn = dbus_player_connect_to_dbus();

    // Register method call?
    if (do_register) {

        // Create a receiver object
        if (!service_object)  {
            service_object = skype_service_new();
        }

        dbus_g_object_type_install_info(G_TYPE_FROM_INSTANCE(service_object), &dbus_glib_server_object_object_info);
        dbus_g_connection_register_g_object(dbus_conn, SKYPE_SERVICE_PATH, (GObject*)service_object);

        g_print("Setup of service object and notify calls done and OK.\n");

    } else {
        // Unregister. Finalize the object.
        if (service_object)
            g_object_unref(service_object);

        service_object = NULL;
    }
}

void init_skype_connection(void) { 

    // Skype service (notify) object
    // service_object = g_object_new(TYPE_SKYPE_SERVICE, NULL);

    gchar *ret = NULL;

    // Send name
    ret = skype_send_message("NAME Robotic Desk Lamp Skype Interface");
    // OK or 
    // ERROR 68 = Access denied.

    if (ret) {
        g_print("Got=<%s>\n", ret);
        g_free(ret);
    }

    // Settle protocol
    ret = skype_send_message("PROTOCOL 7"); // Try also "PROTOCOL 2" etc.
    if (ret) {
        g_print("Got=<%s>\n", ret);
        g_free(ret);
    }

    // Connect notify methods
    skype_setup_notify_methods(TRUE/*register*/);
}

void clean_up(void) {
    g_print("Clean up.\n");

    skype_setup_notify_methods(FALSE/*disconnect*/);
    g_object_unref(proxy_send);
    dbus_g_connection_unref(g_dbus_conn);
}

int main(int argc, char **argv) {

    ros::init(argc, argv, "skype_interface");
    ros::NodeHandle n;
    skype_pub = n.advertise<std_msgs::String>("skype_interface/msg", 100);

    g_thread_init(NULL);
    g_type_init();
    dbus_g_thread_init();



    init_skype_connection();

    while(ros::ok()) {
    	gtk_main_iteration ();
    }

    return 0;
}
