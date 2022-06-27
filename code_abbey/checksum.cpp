#include <iostream>
#include <vector>
#include <array>
using namespace std;

vector <long> input()
{
	cout << "input data:\n";
	int qty;
	cin >> qty;

	vector <long> input_data;
	long j = 0;

	for (int i = 0; i < qty; i++)
	{
		cin >> j;
		input_data.push_back(j);
	}
	return input_data;
}

long long process(vector<long>input_data)
{
	long seed = 113;
	long long result = 0;
	long limit = 10000007;
	for (int i = 0; i < input_data.size(); i++)
	{
		result = (result + input_data[i]) * seed % limit;
	}
	return result;
}

void output(long long result)
{
	cout << "answer:" << endl;
	cout << result << endl;
}

int main()
{
	auto data = input();
	auto result = process(data);
	output(result);

	return 0;
}