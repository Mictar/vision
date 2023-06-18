#ifndef VIDEOPLAYER_HPP
#define VIDEOPLAYER_HPP
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <thread>

class Player
{
	std::string v_name;
	cv::VideoCapture cap;
	cv::Mat frame;
	
	bool crt;

	bool gray, hsv;

	public:
		Player(std::string video_name);

		/*
		 * fonction pausse video
		 */
		void pausse();

		void play();

		void capture(std::string filename);
		
		cv::Mat color(cv::Mat& image);

		bool cmd();

};

#endif
