#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
using namespace std;

vector <int> input()
{
	int a, b, c;
	vector <int> input_data;
	cout << "input data:" << endl;
	cin >> a >> b;
	for (int i = 0; i < a; i++)
	{
		cin >> c;
		input_data.push_back(c);
	}
	return input_data;
}

map <int,int> process(vector<int> data)
{
	map <int, int> occurrences;
	for (int i = 0; i < data.size(); i++)
	{
		occurrences[data[i]]++;
	}
	return occurrences;
}

void output(map <int,int> counts)
{
	for (int i = 1; i <= counts.size(); i++)
	{
		cout << counts[i] << " ";
	}
}

int main()
{
	auto data = input();
	auto counts = process(data);
	output(counts);

	return 0;
}