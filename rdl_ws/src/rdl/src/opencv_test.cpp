#include <stdio.h>
#include <opencv/cv.h>
#include <cxcore.h>
#include <opencv/highgui.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
cvNamedWindow("Capture Video");
CvCapture* capture=cvCaptureFromCAM(2);
IplImage* frame;
while(1) {
  frame = cvQueryFrame(capture);
  cvShowImage("Capture Video", frame);
  char c = cvWaitKey(33);
  if(c == 27) break;
}
cvReleaseImage(&frame);
cvDestroyWindow("Capture Video");

return 0;
}
