#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
using namespace std;

vector<vector<int>> input(int &a, int &b, int &qty)
{
	vector<int> one_set;
	vector<vector<int>> all_sets;

	cout << "input data:" << endl;
	cin >> qty;
	for (int i = 0; i < qty; i++)
	{
		cin >> a >> b;
		one_set.push_back(a);
		one_set.push_back(b);

		all_sets.push_back(one_set);

		one_set.clear();
	}

	return all_sets;
}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
	return (a * b / gcd(a, b));
}

vector<vector<int>> process(int &qty, vector<vector<int>> data)
{
	vector <int> pair;
	vector<vector<int>> final;
	
	for (int i = 0; i < qty; i++)
	{
		int c = gcd(data[i][0], data[i][1]);
		int d = lcm(data[i][0], data[i][1]);

		pair.push_back(c);
		pair.push_back(d);

		final.push_back(pair);

		pair.clear();
	}

	return final;
}

void output(vector<vector<int>> sets)
{
	for (int i = 0; i < sets.size(); i++)
	{
		cout << "(" << sets[i][0] << " " << sets[i][1] << ") ";
	}
}

int main(void)
{
	int a, b, qty;
	auto data = input(a, b, qty);
	auto results = process(qty, data);
	output(results);

	return 0;
}