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

	Mat img = imread("ss.jpg");			//�ι�° �Ķ���� 0���� �����ϸ� ������� ���
	namedWindow("imageWindow", 0);		//�ι�° �Ķ���� �� 0�̸� ������¡ ����, 1�̸� ���� ũ�� �״�� ��µǰ� ������¡ �� ��.
	imshow("imageWindow", img);
	
	//waitKey(1000);	1���� â �ݱ�

	while (1){
		int keyValue;
		keyValue = waitKey(0);
		cout << keyValue << endl;
		if (keyValue == 'c')
			break;
	}

	return 0;
}