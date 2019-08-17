//Simple array processing

#include <iostream>
#include <vector>
using namespace std;


// Sum written to use a.size() in place of N

int sum(vector<int> a, int n)
{
	int  s = 0;

	for (int i = 0; i < n; ++i)
		s += a[i];
	return s;
}

const int  N = 100;

int main()
{
	int a[N];

	int  i;

	for (i = 0; i < N; ++i)
		a[i] = i;
	// create vector from a
	vector<int> first_vector(a, a + N);
	cout << "\nSum is = " << sum(first_vector) << endl;
}