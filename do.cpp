// Use of typical do statement
#include <iostream>
using namespace std;
int main() {
	int sum = 0, n;
	cout << "\nYou must enter 10 positive integers";
	for (int i = 0; i < 10; ++i) {
		// loop until a positive integer is entered
		do {
			cout << "\nEnter a positive integer: ";
			cin >> n;
		} while (n <= 0);
		sum = sum + n;
	}
	cout << "Sum of 10 positive numbers is "
		<< sum << endl;
}