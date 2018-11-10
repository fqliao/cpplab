#include <boost/progress.hpp>
#include <iostream>
#include <sstream>

int main()
{
	std::stringstream ss;
	{
		boost::progress_timer t(ss);
	}
	std::cout << ss.str();
}
