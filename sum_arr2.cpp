// Simple array processing

#include <iostream>
using namespace std;

const int  N = 100;

int main()
{
	int  a[N], *p;
	int  i, sum;

	for (i = 0; i < N; ++i) {
		a[i] = i * i;
		cout << "a[" << i << "] = " << a[i] << "  ";
	}

	sum = 0;
	for (p = a; p < &a[N]; ++p)
		sum += *p;
	cout << "\nsum = " << sum << endl;


	sum = 0;
	for (i = 0; i < N; ++i)
		sum += a[i];
	cout << "\nsum = " << sum << endl;
}