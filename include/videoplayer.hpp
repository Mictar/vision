#ifndef VIDEOPLAYER_HPP
#define VIDEOPLAYER_HPP

class Player
{
	std::string v_name;
	cv::VideoCapture cap;
	cv::Mat frame;
	public:
		Player(std::string video_name);
};

#endif
