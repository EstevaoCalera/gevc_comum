#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp" 
#include <iostream>

using namespace cv;
using namespace std;

int val_med, val_bil, i;
Mat imgMed, img, dst, imgHSV;

vector<Mat> channels(3);

/*void Median_Blur(int, void*){
	//int i = 2*val_med+1;
	int i = 31;
    medianBlur(img,dst,i);
	imshow("Result Image",dst);
}

void Bilateral_Filter(int, void*){
	//int i = 2*val_bil+1;
    int i = 31;
	bilateralFilter(img,dst,i,i*2,i/2);
	imshow("Result Image",dst);
}*/

int main( int argc, char* argv[] )
{
	char* imageName = argv[1];

   	img = imread(imageName, IMREAD_COLOR);

	namedWindow("Original Image",WINDOW_NORMAL);

	moveWindow("Original Image",100,0);
	
	
	//createTrackbar("Median Blur : ","Result Image",&val_med,15,Median_Blur);
	//createTrackbar("Bilateral Filter : ","Result Image",&val_bil,15,Bilateral_Filter);
	//Median_Blur(0,0);
	//Bilateral_Filter(0,0);


    cvtColor(img, imgHSV, COLOR_BGR2HSV);
    split(img, channels);

    namedWindow("channel_1", WINDOW_NORMAL);
	namedWindow("channel_2", WINDOW_NORMAL);
	namedWindow("channel_3", WINDOW_NORMAL);

	

	imshow("Original Image", img);
	imshow("channel_1", channels[0]); 
	imshow("channel_2", channels[1]); // Melhor canal, aparentemente
	imshow("channel_3", channels[2]);

	waitKey(0);
	destroyAllWindows();

	medianBlur(channels[0],imgMed,17);
    bilateralFilter(imgMed,dst,31,62,15.5);

	namedWindow("Result Image",WINDOW_NORMAL);
	resizeWindow("Result Image",Size(700,700));
	moveWindow("Result Image",500,0);
    imshow("Result Image",dst);

	waitKey(0);
    
    Mat imgThresholded;
    /*namedWindow("Control", CV_WINDOW_NORMAL);//criarei a janela "Control" para receber os ranges
    //Crio minhas variáveis que realizaram o controle de reconhecimento das cores
    int iLowH = 0;
    int iHighH = 179;

    int iLowS = 109; 
    int iHighS = 255;

    int iLowV = 45;
    int iHighV = 255;

    //Crio trackbars na janela "Control" para as variaveis anteriores 
    createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
    createTrackbar("HighH", "Control", &iHighH, 179);

    createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
    createTrackbar("HighS", "Control", &iHighS, 255);

    createTrackbar("LowV", "Control", &iLowV, 255);//Value (0 - 255)
    createTrackbar("HighV", "Control", &iHighV, 255);

	namedWindow("Thresholded Image",WINDOW_NORMAL);

	while (waitKey(33) != 27){
	inRange(dst, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded);
    imshow("Thresholded Image", imgThresholded);
	}*/

	namedWindow("Thresholded Image",WINDOW_NORMAL);
	inRange(dst, Scalar(0, 0, 0), Scalar(179, 0, 0), imgThresholded);
    imshow("Thresholded Image", imgThresholded);

	waitKey(0);
    
	dst.release();
	imgMed.release();
    img.release();
	return 0;
}
