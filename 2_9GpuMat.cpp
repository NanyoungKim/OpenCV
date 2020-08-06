#include <opencv2\opencv.hpp>
#include "opencv2\cuda.hpp"
//#include "opencv\cudaarithm.hpp"
//#include "opencv2\cudafilters.hpp"
#include <iostream>

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

	cv::cuda::GpuMat gpuImg, gpuImg_out;

	//1. �̹��� �о����
	Mat img, img_out, img_out2;
	img = imread("ss.jpg");

	//cpu�� �̹����� gpu�� �÷��� ó��
	gpuImg.upload(img);
	cuda::bitwise_not(gpuImg, gpuImg_out);

	//cpu�� �ٽ� �ٿ��ؼ� ���
	gpuImg_out.download(img_out);
	imshow("cpu_img", img);


	waitKey(0);

	return 0;
}