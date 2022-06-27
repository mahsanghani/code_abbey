#include <string>
#include <istream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <double> input()
{
	cout << "data:\n";
	int qty;
	cin >> qty;

	vector <double> input_data;
	double j = 0.0;

	for (int i = 0; i < qty; i++)
	{
		cin >> j;
		input_data.push_back(j);
	}
	return input_data;
}

vector<int> process(vector<double>input_data)
{
	vector<int> dice;
	for (int i = 0; i < input_data.size(); i++)
	{
		input_data[i] = floor(input_data[i]*6);
		dice.push_back(input_data[i]+1);
	}
	return dice;
}

void output(vector<int> dice)
{
	for (int i = 0; i < dice.size(); i++)
	{
		if (i == dice.size() - 1)
		{
			cout << dice[i];
		}
		else
		{
			cout << dice[i] << " ";
		}
	}
}

int main()
{
	auto data = input();
	auto dice = process(data);
	output(dice);

	return 0;
}