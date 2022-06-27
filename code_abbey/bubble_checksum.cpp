#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
using namespace std;

vector <long> input()
{
	cout << "input data:\n" << endl;
	string j;
	vector <long> input_data;
	while (true)
	{
		cin >> j;
		if (j == "-1")
		{
			break;
		}
		input_data.push_back(stoi(j));
	}

	return input_data;
}

long long process(int &n, vector<long> input_data)
{
	int m;
	n = 0;
	for (int i = 0; i < input_data.size()-1; i++)
	{
		if (input_data[i] > input_data[i+1])
		{
			m = input_data[i];
			input_data[i] = input_data[i+1];
			input_data[i+1] = m;
			n++;
		}
	}

	long seed = 113;
	long long result = 0;
	long limit = 10000007;
	for (int i = 0; i < input_data.size(); i++)
	{
		result = (result + input_data[i]) * seed % limit;
	}
	return result;
}

void output(int &n,long long result)
{
	cout << "answer:" << endl;
	cout << n << " " << result << endl;
}

int main(void)
{
	int n; //swaps
	auto data = input();
	auto result = process(n,data); //checksum
	output(n, result);

	return 0;
}