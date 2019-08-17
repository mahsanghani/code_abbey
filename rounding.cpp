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
	int rounding[1024];
	int temp_array[1024];

	for (int i = 0; i < qty2; i++)
	{
		cin.getline(numbers, 1024);

		int x, y, input;
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

		int divide = temp_array[0] / temp_array[1];
		double remaining = temp_array[0] % temp_array[1];

		cout << divide << endl;
		cout << remaining << endl;

		if (abs(remaining) < temp_array[1] / 2)
			rounding[i] = divide;
		
		if (divide > 0)
			if (abs(remaining) >= abs(temp_array[1] / 2) )
				rounding[i] = divide + 1;
			else if (abs(remaining) < abs(temp_array[1] / 2))
				rounding[i] = divide;

		if (divide < 0)
			 if (abs(remaining) >= abs(temp_array[1] / 2))
				rounding[i] = divide - 1;
			else if (abs(remaining) < abs(temp_array[1] / 2))
				rounding[i] = divide;

		if (divide < 1 && divide > -1)
			if (abs(remaining / temp_array[1]) < abs(temp_array[1] / 2))
				rounding[i] = 0; 
			else if (remaining / temp_array[1] > 0)
				rounding[i] = 1;
			else if (remaining / temp_array[1] < 0)
				rounding[i]=-1;
	}

	cout << "answer:\n" << endl;
	for (int i = 0; i < qty2; i++)
		cout << rounding[i] << " ";
}
