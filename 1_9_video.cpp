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
	VideoCapture capture(".\\cat.avi");		// '\'�� Ư�������̹Ƿ� �ΰ� �������
											//�Ķ���͸� �ε����� �� ���� ����. 0�̸� ���� ��ķ. 
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
		if (waitKey(10) == 27) //ESC �� 27��. ESC Ű ������ ����
			break;
	}

	return 0;
}