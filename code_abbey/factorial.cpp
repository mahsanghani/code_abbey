//Recursive factorial function

#include <iostream>
using namespace std;

// Recursive factorial function

long factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * factorial(n - 1);
}

int main()
{
	int i;
	cout << "enter factorial number: ";
	cin >> i;
	cout << "\nFactorial of " << i << " is " << factorial(i) << endl;
}