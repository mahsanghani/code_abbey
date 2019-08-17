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
	int least_array[1024];
	int temp_array[1024];

	for (int i = 0; i < qty2; i++)
	{
		cin.getline(numbers, 1024);

		int x, y, least, input;
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


		if (temp_array[0] < temp_array[1] && temp_array[0] < temp_array[2])
			least_array[i] = temp_array[0];
		else if (temp_array[1] < temp_array[2] && temp_array[1] < temp_array[0])
			least_array[i] = temp_array[1];
		else if (temp_array[2] < temp_array[0] && temp_array[2] < temp_array[1])
			least_array[i] = temp_array[2];
	}
	cout << "answer:\n" << endl;
	for (int i = 0; i < qty2; i++)
		cout << least_array[i] << " ";
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