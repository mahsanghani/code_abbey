#include <iostream>
using namespace std;

inline double cube(double x)
{
	return (x * x * x);
}

int main()
{
	int x;
	cout << "enter an integer: ";
	cin >> x;
	cout << "\nCube of " << x << " is " << cube(x) << endl;
}