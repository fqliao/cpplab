#include <boost/version.hpp>
#include <boost/config.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>

using namespace std;

int main()
{
	//version.hpp
    cout << BOOST_VERSION << endl;
    cout << BOOST_LIB_VERSION << endl;

    //config.hpp
    cout << BOOST_PLATFORM << endl;
    cout << BOOST_COMPILER << endl;
    cout << BOOST_STDLIB << endl;

    //lexical_cast.hpp
    using boost::lexical_cast;
    int a = lexical_cast<int>("123456");
    double b = lexical_cast<double>("123.456");
    cout << a << endl;
    cout << b << endl;

    return 0;
}
