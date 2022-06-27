#include <iostream>
using namespace std;

int compute_sum(int n)  // sum from 1 to n 
{
	int   sum = 0;

	for (; n > 0; --n)  // value of n is changed
		sum += n;
	return sum;
}

int main()
{
	int   n = 3, sum;

	cout << n << endl;     // 3 is printed
	sum = compute_sum(n);
	cout << n << endl;     // 3 is printed
	cout << sum << endl;   // 6 is printed
}