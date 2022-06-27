// Pointer-based call-by-reference

#include <iostream>
using namespace std;

void  order(int*, int*);

int main()
{
	int  i = 7, j = 3;

	cout << i << '\t' << j << endl;    	// 7  3 printed
	order(&i, &j);
	cout << i << '\t' << j << endl;    	// 3  7 printed
}

void order(int* p, int* q)
{
	int  temp;

	if (*p > *q) {
		temp = *p;
		*p = *q;
		*q = temp;
	}
}