#include <iostream>
#include <opencv2\opencv.hpp>


#ifdef _DEBUG
#pragma comment(lib, "opencv_core2413d.lib")
#pragma comment(lib, "opencv_imgproc2413d.lib")
#pragma comment(lib, "opencv_highgui2413d.lib")
//#pragma comment(lib, "opencv_video2413d.lib")
#else
#pragma comment(lib, "opencv_core2413.lib")
#pragma comment(lib, "opencv_imgproc2413.lib")
#pragma comment(lib, "opencv_highgui2413.lib")
//#pragma comment(lib, "opencv_video2413.lib")#endif
#endif

using namespace std;
using namespace cv;



void main() {

	VideoCapture stream1(1);

	if (!stream1.isOpened()) {
		cout << "cannot open camera";
	}

	namedWindow("Processing");
	namedWindow("Origin");

	while (true) {
		//Mat cameraFrame = Mat::zeros(1000, 1000, CV_8U);
		Mat cameraFrame;
		stream1.read(cameraFrame);
		imshow("Origin", cameraFrame);

		Sobel(cameraFrame, cameraFrame, CV_8U, 1, 0);
		imshow("Processing", cameraFrame);

		if (waitKey(30) >= 0)
			break;
	}

	destroyAllWindows();

}


