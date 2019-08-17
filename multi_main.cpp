#include "pgm.h"
int main()
{
	char ans;
	int k, n = N;
	cout << "This program does not do very much.\n";
	cout << "Do you want more information? ";
	cout << "Enter either y or Y if yes. " << endl;
	cin >> ans;
	if (ans == 'y' || ans == 'Y')
		prn_info("multi_main");
	for (k = 0; k < n; ++k)
		fct1(k);
	cout << "Best Regards!" << endl;
}