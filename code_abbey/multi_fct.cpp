#include "pgm.h"

void fct1(int n)
{
	int   i;

	cout << "Hello from fct1()" << endl;
	for (i = 0; i < n; ++i)
		fct2();
}

void fct2()
{
	cout << "Hello from fct2()" << endl;
}