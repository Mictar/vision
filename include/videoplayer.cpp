

#include "videoplayer.hpp"


Player::Player(std::string video_name): cap(video_name), crt(false)
{	
	//cap.open(video_name);
	v_name = video_name;
	printf("[*] play video : %s\n", video_name.c_str());

}

void Player::pausse()
{
	printf("[*] pausse video %s\n", v_name.c_str());
	crt = true;

}

void Player::capture(std::string filename)
{
	cv::imwrite(filename, frame);
	printf("[*] save image %s\n", filename.c_str());
}

cv::Mat Player::color(cv::Mat& image)
{
	cv::Mat result;
	if( gray == true) 
	{ 
		cv::cvtColor(image, result, cv::COLOR_BGR2GRAY);
	}

	else if ( hsv == true)
	{
	
		cv::cvtColor(image, result, cv::COLOR_BGR2HSV);
	}
	else
		result = image;
	return result;
}

void Player::play()
{
	for(;;)
	{
		if ( !crt )
		{
			cap >> frame;

			if ( frame.empty() )
			{
				printf("[*] video is finisj to play %s\n", v_name.c_str());
				break;
			}
			
			frame = color(frame);
			cv::imshow(v_name, frame);
			cv::waitKey(33);
		}
	}
}

bool Player::cmd()
{
	std::string commande;
	while( true )
	{
		std::cout<< "[*] entrer commande : " ;
		std::cin >> commande;

		if( commande == "pausse")
		{
			crt = true;
		}
		else if( commande == "play" )
		{
			crt = false;
		}
		else if ( commande == "gray" ) gray = true, hsv = false;

		else if ( commande == "hsv" ) gray = false, hsv = true;

		else if ( commande == "original" ) gray = false, hsv = false;

		else if ( commande == "save" )
		{
			std::string filename;
			std::cout << "[*] give a filename : ";
			std::cin >> filename;
			capture(filename);
		}
		else if ( commande == "quit" or commande == "exit") exit(1);

		else
			printf("[*] commande not found\n");

	}
}	
