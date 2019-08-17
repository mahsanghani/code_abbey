
#include <iostream>
using namespace std;

double circle(double);	//functions are of scope extern

int main()
{
	double  x;
	cout << "gimme a radius, quick: ";
	cin >> x;
	cout << circle(x)
		<< " is area of  circle of radius "
		<< x << endl;

}