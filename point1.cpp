#include <string>
#include <iostream>
using namespace std;

struct point {
	double x, y;
	void  print() const {
		cout << "(" << x << "," << y
			<< ")";
	}
	void  print(const string& name) const;
	void  set(double u, double v) { x = u; y = v; }
	void  plus(point c);
};


// offset the existing point by point c

void  point::plus(point c)   	// definition not inline
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
	point w1, w2;
	w1.set(0, 0.5);
	w2.set(-0.5, 1.5);
	cout << "\npoint w1 = ";
	w1.print();
	cout << "\npoint w2 = ";
	w2.print();
	w1.plus(w2);
	w1.print();                     	// standard print
	w1.print("\npoint w1 = ");      	// print with name
	cout << "\nAll Done!" << endl;
}