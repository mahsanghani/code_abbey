#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
using namespace std;

string input()
{
	cout << "input data:" << endl;
	char c;
	string input_string;
	getline(cin, input_string);
	return input_string;
}

vector <char> process(string input_string)
{
	vector<char> reverse;
	for (int i = input_string.size()-1; i >= 0; i--)
	{
		reverse.push_back(input_string[i]);
	}
	return reverse;
}

void output(vector<char> reverse)
{
	cout << "answer:" << endl;
	for (int i = 0; i <reverse.size(); i++)
	{
		cout << reverse[i];
	}
}

int main(void)
{
	auto input_string = input();
	auto reverse = process(input_string);
	output(reverse);

	return 0;
}