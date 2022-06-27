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
	int sum = 0;
	char numbers[1024];
	cout << "input data:\n";
	cin.getline(qty,5);
	cin.getline(numbers,1024);

	//cout << "Quantity: \n" << qty;
	//cout << "\nNumbers: \n" << numbers;

	char *token;
	char *rest;
	token = strtok_s(numbers," ", &rest);
	while (token)
	{
		int input = stoi(token);
		//cout << input;
		sum += input;
		token = strtok_s(NULL," ", &rest);
	}
	cout << "answer:\n" << sum;
}