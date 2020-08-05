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

	namedWindow("img", 1);
	Mat img = imread("ss.jpg");

	cout << img.elemSize() << endl;		//�� �ȼ��� ���� ����Ʈ ������
	cout << img.channels() << endl;		//rgb�� 3ä��
	cout << img.rows << endl;				
	cout << img.step << endl;			//������ ���� ����Ʈ �� 


	//1. at approach
	for (int i = img.rows / 10 * 2; i < img.rows / 10 * 3; ++i)
	{
		for (int j = 0; j < img.cols; ++j){
			
			//Ved 3b means "uchar 3ch'
			unsigned char b = img.at< cv::Vec3b>(i, j)[0];
			unsigned char g = img.at< cv::Vec3b>(i, j)[1];
			unsigned char r = img.at< cv::Vec3b>(i, j)[2];

			//������Ű��
			img.at< cv::Vec3b>(i, j)[0] = unsigned char(255 - b);
			img.at< cv::Vec3b>(i, j)[0] = unsigned char(255 - g);
			img.at< cv::Vec3b>(i, j)[0] = unsigned char(255 - r);

		}
	}
	//imshow("img", img);


	//2. ptr approach
	for (int i = img.rows / 10 * 5; i < img.rows / 10 * 6; ++i)
	{
		cv::Vec3b* ptr = img.ptr< cv::Vec3b >(i);		//ptr : i��° row �� ����Ŵ
		for (int j = 0; j < img.cols; j++){

			//ù��° ���
			unsigned char b1 = (ptr[j][0]);		//j��° �÷�, 0��° ä�� 
			unsigned char g1 = (ptr[j][1]);
			unsigned char r1 = (ptr[j][2]);


			//�ι�° ���-> �� ����� ���
			cv::Vec3b bgr = ptr[j];
			unsigned char b2 = (bgr[0]);
			unsigned char g2 = (bgr[1]);
			unsigned char r2 = (bgr[2]);

			ptr[j] = cv::Vec3b(255 - b1, 255 - g1, 255 - r1);		//�������Ѽ� j��° �÷��� �ִ´�.

		}

	}
	imshow("img", img);





	//3. iterator approach
	cv::MatIterator_<cv::Vec3b> itd = img.begin< cv::Vec3b>(), itd_end = img.end < cv::Vec3b>();
	for (int i = 0; itd != itd_end; ++itd, ++i){
		cv::Vec3b bgr = (*itd);

		(*itd)[0] = 255 - bgr[0];
		(*itd)[1] = 255 - bgr[1];
		(*itd)[2] = 255 - bgr[2];
	}


	waitKey(0);

	destroyAllWindows();
	return 0;
}
