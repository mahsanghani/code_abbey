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
	char string[99];
	cout << "input data:\n";
	cin.getline(qty, 5);

	int qty2 = stoi(qty);
	int temp_array[99];

	int vowels, consonants, digits, spaces;
	
	for (int i = 0; i < qty2; i++)
	{
		cin.getline(string, 99);
		vowels = consonants = digits = spaces = 0;
		for (int j = 0; string[j] != '\0'; ++j)
		{
			if (string[j] == 'a' || string[j] == 'e' || string[j] == 'i' ||
				string[j] == 'o' || string[j] == 'u' || string[j] == 'y' || 
				string[j] == 'Y' || string[j] == 'A' || string[j] == 'E' || 
				string[j] == 'I' || string[j] == 'O' || string[j] == 'U')
			{
				++vowels;
			}
		}
		temp_array[i] = vowels;
	}

	cout << "answer:\n" << endl;
	for (int k = 0; k < qty2; k++)
		cout << temp_array[k] << " ";
}