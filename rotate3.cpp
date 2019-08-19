// https://www.codeabbey.com/index/task_view/rotate-string

#include <iostream> 
#include <istream>
#include <sstream> 
#include <stdio.h> 
#include <string.h> 
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<string>> input()
{
	cout << "input data:" << endl;
	int count;
	cin >> count;
	string position, raw_string;
	vector<string> one_set;
	vector<vector<string>> all_sets;
	for (int i = 0; i < count; i++)
	{
		cin >> position >> raw_string;
		one_set.push_back(position);
		one_set.push_back(raw_string);
		all_sets.push_back(one_set);
		one_set.clear();
	}
	return all_sets;
}

vector<string> process(vector<vector<string>> input_data)
{
	vector<string> rotatedness;
	for (int i = 0; i < input_data.size(); i++)
	{
		int pos = stoi(input_data[i][0]);
		string to_rotate = input_data[i][1];
		if (pos > 0) {
			rotate(to_rotate.begin(), to_rotate.begin() + pos, to_rotate.end());
		}
		else if (pos < 0) {
			rotate(to_rotate.rbegin(), to_rotate.rbegin() - pos, to_rotate.rend());
		}
		rotatedness.push_back(to_rotate);
	}
	return rotatedness;
}

void output(vector<string> output_data)
{
	for (int i = 0; i < output_data.size(); i++)
	{
		cout << output_data[i] << " ";
	}
}

int main(void)
{
	auto data = input();
	auto result = process(data);
	output(result);

	return 0;
}