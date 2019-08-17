#include <iostream>
using namespace std;
int main()
{
	int i = 5; // i is initialized to 5
	char c1 = 'B';
	char c2; // c2 is uninitialized
	double x = 0.777, y = x + i;
	cout << "i = " << i << endl; // print i = 5
	cout << "x = " << x // print x = 0.777
		<< "\ty = " << y << endl; // print y = 5.777
	cout << "c1 = " << c1 << endl; // print c1 = B
	cout << "c2 = " << c2 << endl; // print c2 = ???
}
//2147483647 is the maximum int.
//3.40282e+38 is the maximum float