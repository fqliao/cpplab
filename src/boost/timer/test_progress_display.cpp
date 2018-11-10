#include <boost/progress.hpp>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	vector<string> v(1000000, "aaa");

	ofstream fs("./test.txt");
	boost::progress_display pd(v.size());

	vector<string>::iterator pos;
	for(pos = v.begin(); pos != v.end(); ++pos)
	{
		fs << *pos << endl;
		++pd;
	}  //update progress display
}
