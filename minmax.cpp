#include <iostream> 
#include <sstream> 
#include <stdio.h> 
#include <string.h> 
#include <vector>
#include <array>
using namespace std;

int main()
{
	int qty2 = 300;
	int a = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	char numbers[9999];
	cout << "input data:\n";

	int temp_array[9999];
	cin.getline(numbers, 9999);

	for (i; i < qty2; i++)
	{
		int input;
		char *token;
		char *rest;
		token = strtok_s(numbers, " ", &rest);
		while (token)
		{

			input = stoi(token);
			temp_array[a] = input;
			a++;
			token = strtok_s(NULL, " ", &rest);
		}
	}

	int min = 0;
	int max = 0;

	for (j; j < qty2; j++)
	{
		if (min > temp_array[j])
			min = temp_array[j];
	}

	for (k; k < qty2; k++)
	{
		if (max < temp_array[k])
			max = temp_array[k];
	}

	cout << "answer:\n" << endl;
	cout << max << endl;
	cout << min << endl;
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