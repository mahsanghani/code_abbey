#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
using namespace std;

vector<vector<int>> input()
{
	int qty, d1, h1, m1, s1, d2, h2, m2, s2;
	vector<int> start_end;
	vector<vector<int>> bunch_of_times;

	cout << "input data:" << endl;
	cin >> qty;
	for (int i = 0; i < qty; i++)
	{
		cin >> d1 >> h1 >> m1 >> s1 >> d2 >> h2 >> m2 >> s2;
		start_end.push_back(d1);
		start_end.push_back(h1);
		start_end.push_back(m1);
		start_end.push_back(s1);
		start_end.push_back(d2);
		start_end.push_back(h2);
		start_end.push_back(m2);
		start_end.push_back(s2);

		bunch_of_times.push_back(start_end);

		start_end.clear();
	}
	return bunch_of_times;
}

vector <vector <int>> process(vector<vector<int>>data)
{
	int sec1 = 0;
	int sec2 = 0;
	int sec3 = 0;
	int d3, h3, m3, s3;
	vector <int> one_set;
	vector <vector<int>> all_sets;
	for (int i = 0; i < data.size(); i++)
	{
		sec1 = 0;
		sec2 = 0;
		sec3 = 0;
		d3 = h3 = m3 = s3 = 0;

		sec1 += data[i][0] * 24 * 60 * 60;
		sec1 += data[i][1] * 60 * 60;
		sec1 += data[i][2] * 60;
		sec1 += data[i][3];

		sec2 += data[i][4] * 24 * 60 * 60;
		sec2 += data[i][5] * 60 * 60;
		sec2 += data[i][6] * 60;
		sec2 += data[i][7];

		sec3 = sec2 - sec1;

		s3 = sec3 % 60;
		sec3 = sec3 / 60;
		m3 = sec3 % 60;
		sec3 = sec3 / 60;
		h3 = sec3 % 24;
		sec3 = sec3 / 24;
		d3 = sec3;

		one_set.push_back(d3);
		one_set.push_back(h3);
		one_set.push_back(m3);
		one_set.push_back(s3);

		all_sets.push_back(one_set);
		one_set.clear();
	}
	return all_sets;
}

void output(vector <vector<int>> sets)
{
	for (int i = 0; i < sets.size(); i++)
	{
		cout << "(" << sets[i][0] << " " << sets[i][1] << " " << sets[i][2] << " " << sets[i][3] << ") ";
	}
}

int main(void)
{
	auto data = input();
	auto sets = process(data);
	output(sets);

	return 0;
}