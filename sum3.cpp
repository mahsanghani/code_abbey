#include <iostream> 
#include <sstream> 
#include <stdio.h> 
#include <string.h> 
#include <vector>
#include <array>
using namespace std;

int main()
{
	char qty[5];
	char numbers[1024];
	cout << "input data:\n";
	cin.getline(qty, 5);

	int qty2 = stoi(qty);
	int digit_array[1024];
	int sum_array[1024];
	int temp_array[1024];

	for (int i = 0; i < qty2; i++)
	{
		cin.getline(numbers, 1024);

		int input;
		int j = 0;
		int sum = 0;
		char *token;
		char *rest;
		token = strtok_s(numbers, " ", &rest);
		while (token)
		{

			input = stoi(token);
			temp_array[j] = input;
			j++;
			token = strtok_s(NULL, " ", &rest);
		}

		sum_array[i] = temp_array[0] * temp_array[1] + temp_array[2];
	}

	for (int x = 0; x < qty2; x++)
	{
		int string = sum_array[x];
		for (int i = 0; i < 5; i++)
		{
			temp_array[i] = string % 10;
			string = string / 10;
		}
		int sum = 0;
		for (int i = 0; i < 5; i++)
		{
			sum += temp_array[i];
		}
		digit_array[x] = sum;
	}

	cout << "answer:\n" << endl;
	for (int z = 0; z < qty2; z++) {
		cout << digit_array[z] << " ";
	}
}