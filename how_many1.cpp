#include <string>
#include <iostream>
using namespace std;

int N = 10; //max size of array to work with
int  count = 0;                   	// global count

void how_many(double w[], double x, int& count)
{
	for (int i = 0; i < N; ++i)
		count += (w[i] == x);       	// local count
	++::count;           	// global count tracks calls
}

int main()
{
	const int N = 10;
	int count = 0;        //local count variable to increment
	double val_check = 1.1;  //first search on 1.1
	double array[N] = { 1.1, 2.2, 1.1, 4.4, 5.5 };  //init 1st five values

	cout << "\nInitial counts:   local: " << count << "  global: " << ::count;
	how_many(array, val_check, count);
	how_many(array, 2.2, count);
	cout << "\nNew counts:       local: " << count << "  global: " << ::count;

}
