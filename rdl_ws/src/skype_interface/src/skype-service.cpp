#include "ros/ros.h"
#include "skype-service.h"
#include "std_msgs/String.h"
#include <sstream>

G_DEFINE_TYPE(SkypeService, skype_service, G_TYPE_OBJECT)

ros::Publisher skype_pub;

static void skype_service_finalize (GObject *object)
{
    G_OBJECT_CLASS (skype_service_parent_class)->finalize (object);
}

static void skype_service_class_init (SkypeServiceClass *klass)
{
    GObjectClass *object_class;
    object_class = G_OBJECT_CLASS (klass);
    object_class->finalize = skype_service_finalize;
}

static void skype_service_init (SkypeService *object)
{
    ;
}

SkypeService * skype_service_new (void)
{
    return (SkypeService *) g_object_new(TYPE_SKYPE_SERVICE, NULL);
}

gboolean skype_service_notify_callback(SkypeService *object, gchar *message, GError **error) {
    // Notification messages. Called by Skype to notify its clients.
    g_print("skype_service_notify_callback, message:<%s>\n", message);
    std_msgs::String msg;

    std::stringstream ss;
    ss << message;
    msg.data = ss.str();

    skype_pub.publish(msg);

    return TRUE;
}

