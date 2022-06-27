#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> input()
{
	cout << "data:\n";
	int qty;
	cin >> qty;

	vector<int> input_data;
	int j = 0;

	for (int i = 0; i < qty; i++)
	{
		cin >> j;
		input_data.push_back(j);
	}

	return input_data;
}

vector<int> process(vector<int>input_data)
{
	vector<int> weighted;
	vector<int> digit_vector;
	vector<int> sum_vector;
	for (int i = 0; i < input_data.size(); i++)
	{
		int sum = 0;
		int j;
		int k;
		int num1 = input_data[i];
		int num2 = input_data[i];

		for (j = 0; num1 != 0; j++)			// this loop extracts each digit of a number by using % 10
		{
			digit_vector.push_back(num1 % 10);
			num1 = num1 / 10;
		}
		reverse(digit_vector.begin(), digit_vector.end());
		for (int k = 0; k < digit_vector.size(); k++) 		// this loop is meant to apply a weighted sum to each of the extracted digits
		{
			sum_vector.push_back(num2 % 10);
			num2 = num2 / 10;
			sum += (k + 1) * digit_vector[k];
		}
		weighted.push_back(sum);
		digit_vector.clear();
		sum_vector.clear();
	}
	return weighted;
}

void output(vector<int>weighted)
{
	for (int i = 0; i < weighted.size(); i++)
	{
		if (i == weighted.size() - 1)
			cout << weighted[i];
		else
			cout << weighted[i] << " ";
	}
}
int main()
{
	auto numbers = input();
	auto weighted = process(numbers);
	output(weighted);

	return 0;
}