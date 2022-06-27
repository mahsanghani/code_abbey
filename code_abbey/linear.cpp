#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
using namespace std;

vector <vector<int>> input()
{
	int a, b, c, d, e;
	vector <int> coordinates;
	vector <vector<int>> set_of_coordinates;

	cout << "input data:" << endl;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> b >> c >> d >> e;
		coordinates.push_back(b);
		coordinates.push_back(c);
		coordinates.push_back(d);
		coordinates.push_back(e);

		set_of_coordinates.push_back(coordinates);

		coordinates.clear();
	}
	return set_of_coordinates;
}

vector <vector <int>> process(vector<vector<int>>data)
{
	int m, intercept;
	vector <int> one_set;
	vector <vector<int>> all_sets;
	for (int i = 0; i < data.size(); i++)
	{
		// since (b,c,d,e) = (x1 y1 x2 y2)
		
		m = (data[i][3] - data[i][1]) / (data[i][2] - data[i][0]);
		intercept = data[i][3] - m * data[i][2];

		one_set.push_back(m);
		one_set.push_back(intercept);

		all_sets.push_back(one_set);
		one_set.clear();
	}
	return all_sets;
}

void output(vector <vector<int>> sets)
{
	for (int i = 0; i < sets.size(); i++)
	{
		cout << "(" << sets[i][0] << " " << sets[i][1] << ") ";
	}
}

int main(void)
{
	auto data = input();
	auto sets = process(data);
	output(sets);

	return 0;
}