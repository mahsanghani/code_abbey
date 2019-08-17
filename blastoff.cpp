//Recursive factorial function

#include <iostream>
using namespace std;

// Recursive blast_off function

void count_down(unsigned int n)
{
	if (n <= 0)
		cout << "BLAST OFF" << endl;
	else {
		cout << "Count_down at time " << n << endl;
		count_down(n - 1);
	}
}

int main()
{
	unsigned int i = 3;
	count_down(i);
}