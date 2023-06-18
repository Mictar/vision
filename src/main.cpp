#include "videoplayer.hpp"


int main(int argc, char** argv)
{
	Player play { argv[1] };

	std::thread t ( std::bind(&Player::play, &play) );
	std::thread t1 ( std::bind(&Player::cmd ,&play ));
	t.join();
	t1.join();

	return 0;
}
