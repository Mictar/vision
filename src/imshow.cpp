#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	if ( argc < 2) printf("give image name on argument\n"), exit(-1);
	cv::Mat image = cv::imread( cv::String(argv[1]) );

	if ( image.empty() ) printf("File %s is empty\n", argv[1] ), exit(2);

	cv::imshow("image", image);
	cv::waitKey(0);

	return 0;
}
