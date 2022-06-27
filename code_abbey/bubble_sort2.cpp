#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, swap, temp;
	vector<int> arr;
	cout << "Enter n";
	cin >> n;

	// Loop and accept the n values.
	// You may need to take care of the new line.
	for (int i = 0; i < n; ++i)
	{
		cout << "Enter a number : ";
		cin >> temp;
		arr.push_back(temp);
	}

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				swap = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap;
			}
	for (int k = 0; k < n; k++)
		cout << "arr[" << k << "]=" << arr[k] << endl;
	return 0;
}