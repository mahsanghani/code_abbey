#include <iostream> 
#include <sstream> 
#include <stdio.h> 
#include <string.h> 
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	char qty[5];
	char numbers[1024];
	cout << "input data:\n";
	cin.getline(qty, 5);

	int qty2 = stoi(qty);
	string bmi_data[1024];
	float temp_array[1024];

	for (int i = 0; i < qty2; i++)
	{
		cin.getline(numbers, 1024);

		float input;
		int j = 0;
		char *token;
		char *rest;
		token = strtok_s(numbers, " ", &rest);
		while (token)
		{

			input = stof(token);
			temp_array[j] = input;
			j++;
			token = strtok_s(NULL, " ", &rest);
		}

		float bmi = temp_array[0] / (pow(temp_array[1],2));
		if (bmi < 18.5)
		{
			bmi_data[i] = "under";
		}
		else if (bmi < 25 && bmi >= 18.5)
		{
			bmi_data[i] = "normal";
		}
		else if (bmi < 30 && bmi >= 25)
		{
			bmi_data[i] = "over";
		}
		else if (bmi >= 30)
		{
			bmi_data[i] = "obese";
		}
	}
	cout << "answer:\n" << endl;
	for (int i = 0; i < qty2; i++) {
		cout << bmi_data[i] << " ";
	}
}