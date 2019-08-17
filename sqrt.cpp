#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <math.h>
#include <iomanip>
using namespace std;

vector<vector<int>> input(int& a, int& b, int& qty)
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

vector<double> process(vector<vector<int>>input_data)
{
	vector<double> roots;
	for (int i = 0; i < input_data.size(); i++)
	{
		int x = input_data[i][0];
		int n = input_data[i][1];
		double r = 1.0000000;

		for (int j = 0; j < n; j++)
		{
			double x1 = x / r;
			double diff = abs(r - x1);
			r = ((r + x1) / 2);
		}

		roots.push_back(r);
	}

	return roots;
}

void output(vector<double> square_root)
{
	cout << "answer: " << endl;
	for (int i = 0; i < square_root.size(); i++)
	{
		cout << setprecision(12) << square_root[i] << " ";
	}
}

int main(void)
{
	int a, b, qty;
	auto data = input(a, b, qty);
	auto result = process(data);
	output(result);

	return 0;
}