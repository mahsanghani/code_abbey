// Simple array processing

#include <iostream>
using namespace std;

int sum(int a[], int n)       	// n is the size of a[]
{
	int  s = 0;

	for (int i = 0; i < n; ++i)
		s += a[i];
	return s;
}

const int  N = 100;

int main()
{
	int  a[N], *p;
	int k = 10;

	for (int i = 0; i < N; ++i) {
		a[i] = i * i;
		cout << "a[" << i << "] = " << a[i] << "  ";
	}
	cout << "\nsum = " << sum(a, N) << endl;
	cout << "\nsum = " << sum(a, 100) << endl;
	cout << "\nsum first 88 = " << sum(a, 88) << endl;
	cout << "\nsum +7 for 10 = " << sum(a + 7, k) << endl;
}