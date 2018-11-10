#include <memory>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

void demoUse()
{
	shared_ptr<int> sp = make_shared<int>(10);
	assert(sp.use_count() == 1);
	weak_ptr<int> wp(sp);
	assert(sp.use_count() == 1);
	assert(wp.use_count() == 1);
	if (!wp.expired())
	{
		shared_ptr<int> sp2 = wp.lock();
		*sp2 = 100;
		cout << "sp = " << *sp << endl;
		assert(wp.use_count() == 2);
	}
	assert(wp.use_count() == 1);
	sp.reset();
	assert(wp.expired());
	assert(!wp.lock());
}

// note: shared_ptr is a feature of C++11 ,so compile by
// g++ -std=c++11 -ggdb -o test_shared_ptr test_shared_ptr.cpp
// use c++11 gdb
class node
{
public:
	~node(){cout << "deleted" << endl;};
	typedef weak_ptr<node> ptr;
	ptr next;
};

void weak_ptrUse()
{
	auto p1 = make_shared<node>();
	auto p2 = make_shared<node>();
	p1->next = p2;
	p2->next = p1;
	assert(p1.use_count() == 1);
	assert(p2.use_count() == 1);
	if (!p1->next.expired())
	{
		auto p3 = p1->next.lock();
	}
}

int main()
{
	demoUse();
	weak_ptrUse();
}
