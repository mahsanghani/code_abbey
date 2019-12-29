#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <math.h>
#include <iomanip>
using namespace std;

vector<vector<int>> input(int& a, int& b, int& c, int& qty)
{
	vector<int> one_set;
	vector<vector<int>> all_sets;

	cout << "input data:" << endl;
	cin >> qty;
	for (int i = 0; i < qty; i++)
	{
		cin >> a >> b >> c;
		one_set.push_back(a);
		one_set.push_back(b);
		one_set.push_back(c);

		all_sets.push_back(one_set);

		one_set.clear();
	}

	return all_sets;
}

vector<string> process(vector<vector<int>>input_data)
{
	vector<string> triangles;

	for (int i = 0; i < input_data.size(); i++)
	{
		sort(input_data[i].begin(), input_data[i].end());
	}

	for (int i = 0; i < input_data.size(); i++)
	{
		/*int a = input_data[i][0];
		int b = input_data[i][1];
		int c = input_data[i][2];
		int d = pow(a, 2) + pow(b, 2);
		int e = pow(c, 2);*/

		if (pow(input_data[i][0], 2) + pow(input_data[i][1], 2) == pow(input_data[i][2],2)) {
			triangles.push_back("R");
		}
		else if (pow(input_data[i][0], 2) + pow(input_data[i][1], 2) < pow(input_data[i][2],2)) {
			triangles.push_back("O");
		}
		else if (pow(input_data[i][0], 2) + pow(input_data[i][1], 2) > pow(input_data[i][2],2)) {
			triangles.push_back("A");
		}
	}

	return triangles;
}

void output(vector<string> triangles)
{
	cout << "answer: " << endl;
	for (int i = 0; i < triangles.size(); i++)
	{
		cout << triangles[i] << " ";
	}
}

int main(void)
{
	int a, b, c, qty;
	auto data = input(a, b, c, qty);
	auto result = process(data);
	output(result);

	return 0;
}
