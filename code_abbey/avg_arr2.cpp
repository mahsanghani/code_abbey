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

void fill(double a[], const int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = (2.0 * rand()) / RAND_MAX;
}

// Generate data using fill()
int main()
{
	const int size = 20000;
	double a[size];

	fill(a, size);
	cout << "Test array data processing" << endl;
	cout << "average = " << average(a, size) << endl;
	cout << "minimum = " << minimum(a, size) << endl;
	//   cout << "maximum = " << maximum(a, size) << endl;
}