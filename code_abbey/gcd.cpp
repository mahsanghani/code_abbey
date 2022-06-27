// GCD greatest common divisor program
#include <iostream>
using namespace std;
int gcd(int m, int n) // function definition
{ // block begin
	int r; // declaration of remainder
	while (n != 0) { // not equal
		r = m % n; // modulus operator
		m = n; // assignment
		n = r;
	} // end while loop
	return m; // exit gcd with value m
}
int main()
{
	int x, y, howMany;
	cout << "\nPROGRAM GCD C++";
	cout << "\nEnter how many GCD computations? ";
	cin >> howMany;
	for (int i = 0; i < howMany; ++i) {
		cout << "\nEnter two integers: ";
		cin >> x >> y;
		cout << "\nGCD(" << x << ", " << y << ") = "
			<< gcd(x, y) << endl;
	}
}