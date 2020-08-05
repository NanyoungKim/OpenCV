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

	Mat img = imread("ss.jpg");			//두번째 파라미터 0으로 지정하면 흑백으로 출력
	namedWindow("imageWindow", 0);		//두번째 파라미터 값 0이면 리사이징 가능, 1이면 원본 크기 그대로 출력되고 리사이징 안 됨.
	imshow("imageWindow", img);
	
	//waitKey(1000);	1초후 창 닫기

	while (1){
		int keyValue;
		keyValue = waitKey(0);
		cout << keyValue << endl;
		if (keyValue == 'c')
			break;
	}

	return 0;
}