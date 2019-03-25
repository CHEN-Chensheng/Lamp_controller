#include <cv.h>
#include <highgui.h>
#include <opencv2/core/core.hpp>
//#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>


using namespace cv;
using namespace std;

int main(int, char**)
{
    VideoCapture cap(1); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;
    
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    cap.set(CV_CAP_PROP_FPS, 15);

    Mat edges;
    Mat frame;
    Mat corners;

    const int MAX_CORNERS = 100;
    CvPoint2D32f harris_corners[MAX_CORNERS] = {0};
    int harris_corner_count = MAX_CORNERS;
    double harris_quality_level = 0.1;
    double harris_min_distance = 1;
    int harris_eig_block_size = 3;
    bool harris_use_harris = true;
    
    cvNamedWindow("edges",0);
    for(;;)
    {
        cap >> frame; // get a new frame from camera
        
	//transform to grayscale
	//cvtColor(frame, edges, CV_BGR2GRAY);
	//heighten contrast
	//edges.convertTo(edges, -1, 1.5);



	/*	
	goodFeaturesToTrack(	edges,
				corners,
				MAX_CORNERS,
				harris_quality_level,
				harris_min_distance,
				noArray(),
				harris_eig_block_size,
				harris_use_harris);
	*/

        //GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        //Canny(edges, edges, 0, 30, 3);
        cvShowImage("edges", frame);
        if(cvWaitKey(30) >= 0) break;
    }

    //const Mat bla;
    //bla=edges.size();
    cout << "Matrix rows:" << corners.rows  << endl;
    cout << "Matrix columns:" << corners.cols  << endl;

    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
