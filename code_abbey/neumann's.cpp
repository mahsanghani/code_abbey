//https://www.codeabbey.com/index/task_view/neumanns-random-generator

#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
using namespace std;

vector <int> input()
{
	int qty, temp;
	vector<int> input_data;
	cout << "input data:" << endl;
	cin >> qty;
	for (int i = 0; i < qty; i++)
	{
		cin >> temp;
		input_data.push_back(temp);
	}
	return input_data;
}

vector <int> process(vector<int> data)
{
	int last, temp, next;
	vector <int> look_up;
	vector <int> answers;
	for (int i = 0; i < data.size(); i++)
	{
		last = data[i];
		temp = data[i] * data[i];
		look_up.push_back(last);
		for (int j = 1;; j++)
		{
			string temp_string = to_string(temp);
			while (temp_string.size() < 8)
			{
				temp_string.insert(0, 1,'0');
			}
			string new_string = temp_string.substr(2, 4);
			next = stoi(new_string);
			auto it = find(look_up.begin(), look_up.end(), next);
			if (it != look_up.end())
			{
				answers.push_back(j);
				look_up.clear();
				break;
			}
			else
			{
				look_up.push_back(next);
				temp = next*next;
			}
		}
	}

	return answers;
}

void output(vector<int> print)
{
	for (int i = 0; i < print.size(); i++)
	{
		cout << print[i] << " ";
	}
}

int main(void)
{
	auto data = input();
	auto results = process(data);
	output(results);

	return 0;
}