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
	cin.getline(qty,5);

	int qty2 = stoi(qty);
	int sum_array[1024];

	for (int i = 0; i < qty2; i++)
	{
		cin.getline(numbers, 1024);

		//cout << "Quantity: \n" << qty;
		//cout << "\nNumbers: \n" << numbers;

		int sum = 0;
		char *token;
		char *rest;
		token = strtok_s(numbers, " ", &rest);
		while (token)
		{
			int input = stoi(token);
			//cout << input;
			sum += input;
			token = strtok_s(NULL, " ", &rest);
		}
		sum_array[i] = sum;
	}
	cout << "answer:\n" << endl;
	for (int i = 0; i < qty2; i++)
		cout << sum_array[i] << " ";
}

/*//allocate the array
int** arr = new int*[row];
for(int i = 0; i < row; i++)
    arr[i] = new int[col];

// use the array

//deallocate the array
for(int i = 0; i < row; i++)
    delete[] arr[i];
delete[] arr;*/