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
	for(int i=0;i<qty;i++)
	{
		cin >> j;
		input_data.push_back(j);
	}

	return input_data;
}

void process(int &o, int &n, vector<int>input_data)
{
	o = n = 0;
	for (int i = 0; i < input_data.size() - 1; i++)
	{
		int p = 0;
		for (int j = 0; j < input_data.size()-i - 1; j++)
		{
			
			if (input_data[j] > input_data[j + 1])
			{
					int m = input_data[j];
					input_data[j] = input_data[j + 1];
					input_data[j + 1] = m;
					n++; p++;
			}
		}
		o++;
		if (p == 0)
		{
			break;
		}
	}
}

void output(int &o, int &n)
{
	cout << "answer:" << endl;
	cout << o << " " << n << endl;
}

int main(void)
{
	int o,n;
	auto data = input();
	process(o, n, data);
	output(o, n);

	return 0;
}