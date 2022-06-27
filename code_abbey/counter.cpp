#include <string>
#include <iostream>
using namespace std;

// Counter and constructor initialization

class counter {
public:
	counter() { value = 0; }
	counter(int i);       	// ctor declaration
	void  reset() { value = 0; }
	int   get() const { return value; }
	void  print() const { cout << value << '\t'; }
	void  click() { value = (value + 1) % 100; }
private:
	int  value;           	// 0 to 99
};

// Constructor definition

inline counter::counter(int i) { value = i % 100; }

int main()
{

	counter  a(0);       	//a.value = 0;
	counter  b(1);       	//b.value = 1;

	counter  s;           	//initializes s.value to 0
	counter  d[5];        	//arrays properly initialized
	a.print();
	b.print();
	s.print();
	d[1].print();
}