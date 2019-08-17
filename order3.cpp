#include <iostream>
#include <assert.h>
using namespace std;

// Find minimum element in array slice

void order(int& p, int& q)
{
	int  temp = p;

	if (p > q) {
		p = q;
		q = temp;
	}
}

int place_min(int a[], int size, int lowbnd = 0)
{
	assert(size >= 0);        	// precondition
	assert(lowbnd >= 0);      	// precondition
	for (int i = lowbnd; i < lowbnd + size - 1; ++i)
		order(a[lowbnd], a[i + 1]);
	return a[lowbnd];
}

int main()
{
	int   a[9] = { 6, -9, 99, 3, -14, 9, -33, 8, 11 };

	cout << "Minimum = " << place_min(a, 3, 2)
		<< endl;
	assert(a[2] <= a[3] && a[2] <= a[4]); 	// postcondition
}