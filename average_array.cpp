#include <iostream>
#include <vector>
#include <array>
using namespace std;

int size_input()
{
	cout << "data:\n";
	int qty;
	cin >> qty;

	return qty;
}

vector <int> one_line()
{
	vector <int> one_line_vector;
	int j;
	while(true)// need a loop that stops if it finds a line break
	{
		cin >> j;
		if (j == 0)
		{
			break;
		}
		else
		{
			one_line_vector.push_back(j);
		}
	}
	return one_line_vector;
}

int process(vector<int> line)
{
	double sum=0.0;
	for (int i = 0; i < line.size(); i++)
	{
		sum += line[i];
	}
	double average = round(sum / line.size());
	return average;
}

void output(vector<int> average_array)
{
	cout << "\nanswer:" << endl;
	for (int i = 0; i < average_array.size(); i++)
	{
		if (i == average_array.size() - 1)
			cout << average_array[i];
		else
			cout << average_array[i] << " ";
	}
}

int main()
{
	auto qty = size_input();
	vector<int> average_vector;
	for (int i = 0; i < qty; i++) 
	{
		auto line = one_line();
		auto average = process(line);
		average_vector.push_back(average);
	}
	output(average_vector);

	return 0;
}