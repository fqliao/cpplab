#include <memory>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

void demoUse()
{
	typedef vector<shared_ptr<int> > vs;
	vs v(10);
	int i = 0;
	for (auto& ptr : v) //must be reference style
	{
		ptr = make_shared<int>(++i);
		if (i == 10)
			cout << *ptr;
		else
			cout << *ptr << ", ";
	}
	cout << endl;
	shared_ptr<int> p = v[9];
	*p = 100;
	cout << *v[9] << endl;
}

void transferPtr()
{
	shared_ptr<std::exception> sp1 = make_shared<std::bad_exception>();
	// transfer from base to derived by dynamic_pointer_cast<T>()
	shared_ptr<std::bad_exception> sp2 =
			dynamic_pointer_cast<std::bad_exception>(sp1);
	// transfer from derived to base by static_pointer_cast<T>()
	shared_ptr<std::exception> sp3 = static_pointer_cast<std::exception>(sp2);
	assert(sp1 == sp3);
	cout << "sp1 =" << sp1 << endl;
	cout << "sp2 =" << sp2 << endl;
}

// note: shared_ptr is a feature of C++11 ,so compile by
// g++ -std=c++11 -ggdb -o test_shared_ptr test_shared_ptr.cpp
// use c++11 gdb

int main()
{
	demoUse();
	transferPtr();
}
