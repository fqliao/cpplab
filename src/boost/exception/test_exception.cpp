#include <iostream>
#include <boost/exception/all.hpp>
using namespace std;

// note: shared_ptr is a feature of C++11 ,so compile by
// g++ -std=c++11 -ggdb -o test_shared_ptr test_shared_ptr.cpp
// use c++11 gdb

int main()
{
	try {
		BOOST_THROW_EXCEPTION(std::logic_error("logic"));
	} catch (boost::exception& e) {
		//Equivalent to the two ways to print exception information
		cout << boost::diagnostic_information(e) << endl;
		// if catch ... , the way also available
		cout << boost::current_exception_diagnostic_information() << endl;
	}

	try {
		BOOST_THROW_EXCEPTION(std::bad_exception());
	} catch (...) {
		boost::exception_ptr e = boost::current_exception();
		cout << boost::diagnostic_information(e) << endl;
		// if catch ... , the way also available
		cout << boost::current_exception_diagnostic_information() << endl;
	}
}
