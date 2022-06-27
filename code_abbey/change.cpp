// Change in dimes and pennies
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int price, change, dimes, pennies;
	cout << "Enter price (0:100): ";
	cin >> price;
	change = 100 - price; // how much change
	dimes = change / 10; // number of dimes
	pennies = change % 10; // number of pennies
	cout << "\n\nThe change is :"
		<< dimes << " dimes ";
	cout << pennies << " pennies." << endl;
}