#include <string>
#include <iostream>
#include <vector>
using namespace std;

int get_size()
{
	cout << "data:\n";
	char char_size[5];
	cin.getline(char_size, 5);

	int int_size = stoi(char_size);
	return int_size;
}

string input(int size)
{
	string raw_data;
	// iterate
	cin.getline(raw_data, size, "\n");
	return raw_data;
}

vector<int> process(string raw_data)
{
	//convert string to int

	int sum;
	vector<int> sum_data;
	for (int i = 0; i < raw_data.size(); i++)
	{
		for (int j = 0; j < raw_data[i][2]; j++)
		{
			sum += raw_data[i][0] + j * raw_data[i][1];
		}
		sum_data[i] = sum;
	}
	return sum_data;
}

void output(vector<int> sum_data)
{
	cout << "answer:\n" << endl;
	for (int i = 0; i < sum_data.size(); i++)
	{
		cout << sum_data[i] << " ";
	}

	int main()
	{
		int size = get_size();
		string raw_data = input(size);
		vector<int> sum_data = process(raw_data);
		output();

		return 0;
	}