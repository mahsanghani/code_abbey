//Simple array processing

#include <iostream>
using namespace std;

const int M = 3;    // number of rows 
const int N = 4;    // number of column

int main()
{
	int   a[M][N], i, j, sum = 0;

	for (i = 0; i < M; ++i)        // fill the array
		for (j = 0; j < N; ++j)
			a[i][j] = i + j;
	for (i = 0; i < M; ++i) {      // print array
		for (j = 0; j < N; ++j)
			cout << "a[" << i << "][" << j
			<< "] = " << a[i][j] << '\t';
		cout << endl;
	}
	for (i = 0; i < M; ++i)        // sum the array
		for (j = 0; j < N; ++j)
			sum += a[i][j];
	cout << "\nsum =  " << sum << endl;
}