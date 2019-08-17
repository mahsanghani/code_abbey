#include <iostream>
using namespace std;

union int_dbl {
	int     i;
	double  x;
} n = { 0 };

int main()
{
	n.i = 7;             	// int value 7 is stored in n
	cout << n.i << " is integer. " << endl;
	cout << n.x << " is double-machine dependent." << endl;
	n.x = 7.0;           	// double value 7.0 in n
	cout << n.i << " is integer - machine dependent." << endl;
	cout << n.x << " is double." << endl;
}