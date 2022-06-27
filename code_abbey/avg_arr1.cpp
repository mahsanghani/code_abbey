//Simple array processing

#include <iostream>
using namespace std;

double sum(double a[], const int n)  	//n is the size of a[]
{
	double s = 0.0;

	for (int i = 0; i < n; ++i)
		s += a[i];
	return s;
}

double average(double a[], const int n)  	//n is the size of a[]
{
	double s = 0.0;

	for (int i = 0; i < n; ++i)
		s += a[i];
	return s / n;
}

double minimum(const double a[], const int n)
{
	double min = a[0];

	for (int i = 1; i < n; ++i)
		if (min > a[i])
			min = a[i];
	return min;
}


// Simple test of our program
int main()
{
	const int size = 6;
	double a[size] = { 0.5, 1.5, 6.0, 7.5, 2.3, 4.6 };

	cout << "Test array data processing" << endl;
	cout << "average = " << average(a, size) << endl;
	cout << "minimum = " << minimum(a, size) << endl;
	//   cout << "maximum = " << maximum(a, size) << endl;
}