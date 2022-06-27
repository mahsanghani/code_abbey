#include <iostream>
using namespace std;


char  c;           	// external scope  ::c

class X {          	// outer class declaration  X::
public:
	char  c;        	// X::c
	class Y {       	// inner class declaration  X::Y::
	public:
		void foo(char e) { X t; ::c = t.c = c = e; }
		friend ostream& operator<<(ostream& out, X::Y& y);
	private:
		char  c;     	// X::Y::c
	};
};

ostream& operator<<(ostream& out, X& xc)
{
	return (out << "  X::c = " << xc.c << "  " << endl);
}

ostream& operator<<(ostream& out, X::Y& yc)
{
	return (out << "  Y::c = " << yc.c << "  " << endl);
}

int main()
{
	X xclass;
	X::Y yclass;

	c = 'A';               // external to 'A'
	cout << c << xclass << yclass << endl;
	yclass.foo('D');       // set Y::c and ::c to D
	cout << c << xclass << yclass << endl;
}