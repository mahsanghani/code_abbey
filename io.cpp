#include <iostream>
using namespace std;
int main()
{
	int i;
	double x;
	cout << "\nEnter a double: ";
	cin >> x;
	cout << "Enter a positive integer: ";
	cin >> i;
	while (i < 1) {
		cerr << "error i = " << i << endl;
		cout << "Enter a positive integer: ";
		cin >> i;
	};
	cout << "i * x = " << i * x << endl;
}