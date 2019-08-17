#include <iostream>
using namespace std;

// Overloading the structure pointer operator

class triple {
public:
	triple(int a, int b, int c) : i(a), j(b), k(c) { }
	void print() const {
		cout << "i = " << i
			<< ", j = " << j << ", k = "
			<< k << endl;
	}
private:
	int  i, j, k;
};

triple   unauthor(0, 0, 0);
class t_ptr {
public:
	t_ptr(bool f, triple* p) : access(f), ptr(p) { }
	triple*  operator ->();
private:
	bool  access;
	triple*  ptr;
};

triple* t_ptr::operator->()
{
	if (access)
		return ptr;
	else {
		cout << "unauthorized access" << endl;
		return &unauthor;
	}
}

int main()
{
	triple  a(1, 2, 3), b(4, 5, 6);
	t_ptr ta(false, &a), tb(true, &b);

	ta->print();            	// access denied
	tb->print();            	// access granted
}