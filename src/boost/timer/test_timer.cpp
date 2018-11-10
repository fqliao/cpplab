#include <boost/timer.hpp>
#include <iostream>

using namespace std;

int main()
{
	boost::timer timer;
	cout << "max timespan: " << timer.elapsed_max() / 3600 << "h" << endl;
	cout << "min timespan: " << timer.elapsed_min() << "s" << endl;
	sleep(2);
	cout << "now the elapsed:" << timer.elapsed() * 1000 << "s" << endl;
}
