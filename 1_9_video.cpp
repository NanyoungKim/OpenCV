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

int main(int, char){

	//file load
	VideoCapture capture(".\\cat.avi");		// '\'는 특수문자이므로 두개 써줘야함
											//파라미터를 인덱스로 할 수도 있음. 0이면 내장 웹캠. 
	Mat frame;

	//check
	if (!capture.isOpened()){
		printf("AVI file can not open.\n");
		return 0;
	}

	while (1){
		//grap frame rom file & thorw to Mat
		capture >> frame;
		if (frame.empty())	//is viedo end?
			break;

		//processing example
		Sobel(frame, frame, frame.depth(), 1, 0);

		//display and delay
		imshow("w", frame);
		if (waitKey(10) == 27) //ESC 가 27임. ESC 키 누르면 종료
			break;
	}

	return 0;
}