#include <opencv2/opencv.hpp>

enum key{
	PAUSSE,
	PLAY,
	GRAY,
	HSV
};

/*
cv::Mat color(char key, cv::Mat& image)
{
	cv::MAt result;
	if ( key == 'g' )
	{
		cv::cvtColor(image, result, cv::COLOR_BGR2GRAY);
		return result;
	}
	else if ( key == 'h')
	{
		cv::cvtColor(image, result, cv::COLOR_GBR2HSV);
		return result;
	}
	else
		return image;
}
*/
int main(int argc, char** argv)
{
	if ( argc < 2) printf("give video file\n"), exit(-1);

	cv::Mat frame;

	cv::VideoCapture cap { argv[1] };

	bool play = true, pausse = false, gray = false, hsv = false, original= true;
	char c;
	if ( true )
	{
		cap >> frame;
		cv::imshow("video", frame);
		
		for(;;)
		{
			c = cv::waitKey(33);
			
			if ( c == 'p' ) pausse = true, play = false;
			else if ( c == 'r')  play = true, pausse = false;

			else if ( c == 'q' ) { printf("Player quit\n") ; break; }
			else if ( c == 'o' ) gray = hsv = false, original = false;
			else if ( c == 'g' ) original = hsv =false, gray = true;
			else if ( c == 'h' ) original = gray = false, hsv = true;

			if (  pausse )
			{
				//cap >> frame;
			}
			else if ( play )
			{
				cap >> frame;
				
				if ( frame.empty() ) break;
				
				if ( gray ) cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);

				else if ( hsv ) cv::cvtColor(frame, frame, cv::COLOR_BGR2HSV);
				
				//cv::Mat image = color(, frame);
				cv::imshow("video", frame);
			}
		}
	}
	else
	{
		printf("video %s is invalide\n", argv[1] );
		return -1;
	}

	return 1;
}
