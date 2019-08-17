// Examples of scope rules
#include <iostream>
using namespace std;
int b = 15; // file scope
int main()
{
	int a = 2; // outer block a
	cout << a << endl; // prints 2
	{ // enter inner block
		int a = b; // inner block a
		cout << a << endl; // prints 15
	} // exit inner block
	cout << ++a << endl; // 3 is printed
}