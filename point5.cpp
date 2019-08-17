#include <string>
#include <iostream>
using namespace std;

// Class illustrating the use of the this pointer

class point {
public:                 	// place public members first
	void   print() const {
		cout << "(" << x << "," << y
			<< ")";
	}
	void   print(const string& name) const;
	void   set(double u, double v) { x = u; y = v; }
	void   plus(point c);
	point  inverse() { x = -x; y = -y; return (*this); }
	point* where_am_I() { return this; }
private:
	double x, y;
};

// Offset the existing point by point c

void point::plus(point c)
{
	x += c.x;
	y += c.y;
}

void point::print(const string& name) const
{
	cout << name << " (" << x << "," << y << ")";
}

int main()
{
	point  a, b;

	a.set(1.5, -2.5);
	a.print();
	cout << "\na is at " << a.where_am_I() << endl;
	b = a.inverse();
	b.print();
	cout << "\nb is at " << b.where_am_I() << endl;
}