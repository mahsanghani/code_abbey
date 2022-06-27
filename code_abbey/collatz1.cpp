#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
using namespace std;

vector <int> input()
{
	int a, c;
	vector <int> input_data;
	cout << "input data:" << endl;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> c;
		input_data.push_back(c);
	}
	return input_data;
}

vector <int> process(vector<int> data)
{
	vector <int> loop;
	for (int i = 0; i < data.size(); i++)
	{
		int j = 0;
		int b = data[i];
		for (j;b != 1;j++)
		{
			if (b % 2 == 0)
			{
				b = b / 2;
			}
			else
			{
				b = 3 * b + 1;
			}
		}
		loop.push_back(j);
	}
	return loop;
}

void output(vector <int> loop)
{
	for (int i = 0; i < loop.size(); i++)
	{
		cout << loop[i] << " ";
	}
}

int main()
{
	auto data = input();
	auto loop = process(data);
	output(loop);

	return 0;
}