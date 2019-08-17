#include <iostream>
#include <vector>
#include <array>
using namespace std;

vector <int> input() // break into 2
{
	cout << "data:\n";
	int qty;
	cin >> qty;

	vector<int> temp_array;
	int j = 0;

	for (int i = 0; i < qty; i++) // end condition of this loop  is a "0"
	{
		cin >> j;
		temp_array.push_back(j);
	}

	return temp_array;
}

vector<int> process(vector<int>temp_array)
{
	vector<int> celsius;
	for (int i = 0; i < temp_array.size(); i++)
	{
		double f = temp_array[i];
		double c = ((f + 40) / 1.8) - 40;

		celsius.push_back(round(c));
	}
	return celsius;
}

void output(vector<int>celsius)
{
	for (int i = 0; i < celsius.size(); i++)
	{
		if (i == celsius.size() - 1)
			cout << celsius[i];
		else
			cout << celsius[i] << " ";
	}
}
int main()
{
	auto numbers = input();
	auto celsius = process(numbers); // loop this shit
	output(celsius);				// end condition is i < qty

	return 0;
}