#include "ros/ros.h"
//#include "opencv2/opencv.hpp"
#include "book_tracker/book_pos.h"
#include <cv.h>
#include <highgui.h>
#include <stdio.h>


#define VIDEO_WINDOW   "Webcam"
#define CORNER_HARRIS  "Corner Detection (Harris)"

#define USEC_PER_SEC 1000000L

CvScalar target_color[4] = ( // in BGR order
       0,   0, 255,   0   // red
       //0, 255,   0,   0 ,  // green
       //255,   0,   0,   0,  // blue
       //0, 255, 255,   0  ,  // yellow
);

void change_brightcont(IplImage *src_image, IplImage *dst_image, int brightness=0, int contrast=0)
{
    int i;
    uchar lut[256];
    CvMat* lut_mat;
    lut_mat = cvCreateMatHeader( 1, 256, CV_8UC1 );
    cvSetData( lut_mat, lut, 0 );  //The new image--"lut_mat" is just the size of lut

    if( contrast > 0 )
    {
        double delta = 127.*contrast/100;
        double a = 255./(255. - delta*2);
        double b = a*(brightness - delta);
        for( i = 0; i < 256; i++ )
        {
            int v = cvRound(a*i + b);
            if( v < 0 )
                v = 0;
            if( v > 255 )
                v = 255;
            lut[i] = (uchar)v;
        }
    }
    else
    {
        double delta = -128.*contrast/100;
        double a = (256.-delta*2)/255.;
        double b = a*brightness + delta;
        for( i = 0; i < 256; i++ )
        {
            int v = cvRound(a*i + b);
            if( v < 0 )
                v = 0;
            if( v > 255 )
                v = 255;
            lut[i] = (uchar)v;
        }
    }

    cvLUT( src_image, dst_image, lut_mat );
}

// A Simple Camera Capture Framework
int main(int argc, char *argv[]) {
	//double centre[2] = {320, 240};

  CvCapture* capture;
	IplImage* curr_frame = 0; // current video frame
	IplImage* gray_frame = 0; // grayscale version of current frame
	int w, h; // video frame size
	IplImage* harris_eig_image = 0;
	IplImage* harris_temp_image = 0;

	book_tracker::book_pos centre;
	centre.x = 320;
	centre.y = 240;
	
	// Capture from a webcam
  //capture = cvCaptureFromCAM(atoi(*(argv+1)));
  //capture = cvCaptureFromCAM(atoi(*(argv+1)));
  capture = cvCaptureFromCAM(1);
	if ( !capture) {
		fprintf(stderr, "ERROR: capture is NULL... Exiting\n");
		//getchar();
		return -1;
	}
	
	// Create a window in which the captured images will be presented
	cvNamedWindow(VIDEO_WINDOW, 0); // allow the window to be resized

	ros::init(argc, argv, "book_tracker");
	ros::NodeHandle n;
	ros::Publisher bookpos_pub = n.advertise<book_tracker::book_pos>("book_tracker/book_pos", 100);
	
	// Show the image captured from the camera in the window and repeat
	while (true) {
		// Get one frame
		curr_frame = cvQueryFrame(capture);
		if ( !curr_frame) {
			fprintf(stderr, "ERROR: frame is null... Exiting\n");
			break;
		}

		// Get frame size
		w = curr_frame->width;
		h = curr_frame->height;

		// Convert the frame image to grayscale
		if( ! gray_frame ) {
			//fprintf(stderr, "Allocate gray_frame\n");
			int channels = 1;
			gray_frame = cvCreateImage(
					cvGetSize(curr_frame), 
					IPL_DEPTH_8U, channels);
		}
		cvCvtColor(curr_frame, gray_frame, CV_BGR2GRAY);

		//Change Contrast
		change_brightcont(gray_frame, gray_frame, 0, 80);
		//change_brightcont(gray_frame, gray_frame, atoi(*(argv+1)), atoi(*(argv+2)));
		
		// ==== Allocate memory for corner arrays ====
		if ( !harris_eig_image)		harris_eig_image = cvCreateImage(cvSize(w, h), IPL_DEPTH_32F, 1);
		if ( !harris_temp_image)	harris_temp_image = cvCreateImage(cvSize(w, h), IPL_DEPTH_32F, 1);
		
		// ==== Corner Detection: Harris method ====
		const int MAX_CORNERS = 200;
		CvPoint2D32f harris_corners[MAX_CORNERS] = {0};
		int harris_corner_count = MAX_CORNERS;
		double harris_quality_level = 0.02;
		double harris_min_distance = 40;
		int harris_eig_block_size = 3;
		int harris_use_harris = true;
		
		cvGoodFeaturesToTrack(gray_frame,
				harris_eig_image,                    // output
				harris_temp_image,
				harris_corners,
				&harris_corner_count,
				harris_quality_level,
				harris_min_distance,
				NULL,
				harris_eig_block_size,
				harris_use_harris);
		cvScale(harris_eig_image, harris_eig_image, 200, 0.50);
		
		
		// ==== Draw circles around detected corners in original image
		//fprintf(stderr, "corner[0] = (%f, %f)\n", corners[0].x, corners[0].y);
		for( int i = 0; i < harris_corner_count; i++) {
			int radius = h/25;
			cvCircle(gray_frame,
					cvPoint((int)(harris_corners[i].x + 0.5f),(int)(harris_corners[i].y + 0.5f)),
					radius,
					target_color[0]);
		}

		if(harris_corner_count>=4) {
			centre.x = (	harris_corners[0].x +
					harris_corners[1].x +
					harris_corners[2].x +
					harris_corners[3].x)/4;

			centre.y = (	harris_corners[0].y +
					harris_corners[1].y +
					harris_corners[2].y +
					harris_corners[3].y)/4;

			fprintf(stdout, "Schwerpunkt: x=%lf y=%lf no_corners:%i\n", centre.x, centre.y, harris_corner_count);
			bookpos_pub.publish(centre);
			ros::spinOnce();
		}

		cvShowImage(VIDEO_WINDOW, gray_frame);



		// remove higher bits using AND operator
		if ( (cvWaitKey(10) & 255) == 27)
			break;
	}

	// Release the capture device housekeeping
	cvReleaseCapture( &capture);
	cvDestroyWindow(VIDEO_WINDOW);
	return 0;
}

