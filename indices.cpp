#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
using namespace std;

vector <int> input()
{
	int j, qty;
	cout << "input data:\n" << endl;
	cin >> qty;
	vector <int> input_data;
	for (int i = 0; i < qty; i++)
	{
		cin >> j;
		input_data.push_back(j);
	}

	return input_data;
}

vector<int> process(vector<int>input_data)
{
	map<int, int> index;
	for (int i = 0; i < input_data.size(); i++)
	{
		//index[i] = input_data[i];
		index[input_data[i]] = i+1;
	}

	for (int j = 0; j < input_data.size() - 1; j++)
	{	for (int k = 0; k < input_data.size() - j - 1; k++)
		{	if (input_data[k] > input_data[k + 1])
			{
				int temp = input_data[k];
				input_data[k] = input_data[k + 1];
				input_data[k + 1] = temp;
			}
		}
	}

	vector<int> placement;
	for (int m = 0; m < index.size(); m++)
	{
		if (index[m] != 0) {
			placement.push_back(index[m]);
		}
	}

	return placement;
}

void output(vector<int> placement)
{
	cout << "answer: " << endl;
	for (int i = 0; i < placement.size(); i++)
	{
		cout << placement[i] << " ";
	}
}

int main(void)
{
	auto data = input();
	auto result = process(data);
	output(result);

	return 0;
}