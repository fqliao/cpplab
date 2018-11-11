#include <memory>
#include <iostream>
#include <cassert>
#include <vector>
#include <boost/assign.hpp>
using namespace std;

void first()
{
	using namespace boost::assign;
	vector<int> vec;
	vec += 1, 2, 3, 4, 5, 6 * 6; //override += and ,
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	list<string> li; // linked implement,support insert and delete efficiently
	li += "btc", "eth", "eos";
	for (auto l : li)
		cout << l << " ";
	cout << endl;

	set<string> ss;
	ss += "c", "cpp", "lua", "swift";
	for (auto s : ss)
		cout << s << " ";
	cout << endl;

	map<int, string> ma;
	ma += make_pair(1, "one"), make_pair(2, "two");
	for (auto m : ma)
		cout << m.first << " : " << m.second << endl;
}

void second()
{
	using namespace boost::assign;
	vector<int> vec;
	push_back(vec)(1)(2)(3)(4)(5); //override ()
	for (auto v : vec)
		cout << v << " ";
	cout << endl;
	list<string> li; // linked implement,support insert and delete efficiently
	push_front(li)("btc")("eth")("eos");
	for (auto l : li)
		cout << l << " ";
	cout << endl;
	set<string> ss;
	insert(ss)("c")("cpp")("lua")("swift");
	for (auto s : ss)
		cout << s << " ";
	cout << endl;
	map<int, string> ma;
	insert(ma)(1, "fabric")(2, "bcos");
	for (auto m : ma)
		cout << m.first << " : " << m.second << endl;
}

void best()
{
	using namespace boost::assign;
	vector<int> vec;
	vec += 1, 2, 3, 4, 5, 6 * 6; //override += and ,
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	list<string> li; // linked implement,support insert and delete efficiently
	li += "btc", "eth", "eos";
	for (auto l : li)
		cout << l << " ";
	cout << endl;

	set<string> ss;
	ss += "c", "cpp", "lua", "swift";
	for (auto s : ss)
		cout << s << " ";
	cout << endl;

	map<int, string> ma;
	insert(ma)(6, "apple")(8, "orange");
	for (auto m : ma)
		cout << m.first << " : " << m.second << endl;
}

// note: shared_ptr is a feature of C++11 ,so compile by
// g++ -std=c++11 -ggdb -o test_shared_ptr test_shared_ptr.cpp
// use c++11 gdb

int main()
{
//	first();
//	second();
	best();
}
