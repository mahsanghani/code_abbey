#include <iostream> 
#include <sstream> 
#include <stdio.h> 
#include <string.h> 
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
	char qty[5];
	char numbers[1024];
	cout << "input data:\n";
	cin.getline(qty, 5);

	int qty2 = stoi(qty);
	int sort[1024];
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

		std::vector<int> vec(temp_array, temp_array + 3);
		std::sort(temp_array, temp_array +3);
		
		cout << vec << endl;
	}
	cout << "answer:\n" << endl;
	for (int i = 0; i < qty2; i++) {
		cout << sort[i] << " ";
	}
}