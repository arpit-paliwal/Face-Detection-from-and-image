// FD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<stdlib.h>
#include<opencv2\objdetect\objdetect.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

int main() {

	CascadeClassifier faceDetection;
	if (faceDetection.load("C:\\Program Files (x86)\\opencv\\sources\\\haarcascades\\haarcascade_frontalface_default.XML")) {
		cout << "\n File is not loaded properly";
		exit(0);
	}

	char path[100];
	cout << "Enter the path to image for face detection : ";
	cin.getline(path, 100);

	Mat img = imread(path, IMREAD_UNCHANGED);

	if (img.empty()) {
		cout << "\n The image is not loaded properly";
	}
	else {
		cout << "\n Image is found";
		cout << "\n Processing....";

		vector <Rect> faces;
		faceDetection.detectMultiScale(img, faces); // detecting here 

		for (int i = 0; i < faces.size(); i++) {
			Point pt1(faces[i].x, faces[i].y); // first point
			Point pt2((faces[i].x + faces[i].height), (faces[i].x + faces[i].width));
			rectangle(img, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);

		}

		imwrite("C:\\Users\\Arpit\\Desktop\\ Export\\output.jpg", img);

		cout << "\n Fcae detected Successfully !!";

	}
	return(0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
