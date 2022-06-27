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
	cout << "data:\n";
	cin.getline(qty, 5);

	int qty2 = stoi(qty);
	int celsius[1024];
	int temp_array[1024];

	cin.getline(numbers, 1024);

	for (int i = 0; i < qty2; i++)
	{
		int input;
		int j = 0;
		int k = 0;
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
	
		double f = temp_array[i];
		double c = ((f + 40) / 1.8) - 40;
		celsius[i] = round(c);
	}
	cout << "answer:\n" << endl;
	for (int i = 0; i < qty2; i++)
		cout << celsius[i] << " ";
}