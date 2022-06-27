//Recursive factorial function

#include <iostream>
#include <assert.h>
using namespace std;

int sqr_or_power(int n, int k = 2)  	// k=2 is default
{
	assert(k > 1);          	// if false program aborts
	if (k == 2)
		return (n * n);
	else
		return (sqr_or_power(n, k - 1) * n);
}

int main()
{
	unsigned int i = 3;
	cout << "\nans for 3 is " << sqr_or_power(i) << endl;
}