// https://www.codeabbey.com/index/task_view/rotate-string

#include <iostream> 
#include <istream>
#include <sstream> 
#include <stdio.h> 
#include <string.h> 
#include <algorithm>
#include <vector>
using namespace std;

string input(int& position)
{
	string raw_string;
	cin >> position >> raw_string;

	return raw_string;
}

string leftrotate(string& str, int pos)
{
	reverse(str.begin(), str.begin() + pos);
	return str;
}

string rightrotate(string& str, int pos)
{
	leftrotate(str, str.length() - pos);
	return str;
}

string rotate(int& position, string& rotate_string)
{
	string final_string;
	if (position > 0)
	{
		final_string = leftrotate(rotate_string, position);
	}

	if (position < 0)
	{
		final_string = rightrotate(rotate_string, position);
	}

	return final_string;
}

string process(int& position, string input_string)
{
	string final_string = rotate(position, input_string);
	return final_string;
}

void output(vector<string> ready_to_print)
{
	for (int i = 0; i < ready_to_print.size(); i++)
	{
		cout << ready_to_print[i] << " ";
	}
}

int main(void)
{
	int count, position;
	string to_rotate;
	vector<string> ready_to_print;
	cout << "input data:" << endl;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		string raw_string = input(position);
		string final_string = process(position, raw_string);
		ready_to_print.push_back(final_string);
	}
	
	output(ready_to_print);
	return 0;
}