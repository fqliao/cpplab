#include <memory>
#include <iostream>
#include <cassert>

using namespace std;

int main()
{
	shared_ptr<int> sint = make_shared<int>(10);
	cout << *sint << endl;
	assert(sint);
	cout << sint.unique() << endl;
	cout << sint.use_count() << endl;
	shared_ptr<int> sint2 = sint;
	cout << sint.unique() << endl;
	cout << sint.use_count() << endl;
}
