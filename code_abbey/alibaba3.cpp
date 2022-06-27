//
// Created by Ahsan Ghani on 2020-09-14.
//

#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <array>
#include <regex>
#include <iterator>
using namespace std;

vector<string> input()
{
	vector<string>all_sets;
	char qty[5], my_string[1500];
	cout << "input data:" << endl;
	cin.getline(qty, 5);

	int qty2 = stoi(qty);

	for (int i = 0; i < qty2; i++)
	{
		cin.getline(my_string, 1500);
		all_sets.push_back(my_string);
	}
    cout << my_string << endl;
	return all_sets;
}

int main(void)
{
    char str[256];

    std::cout << "Enter the name of an existing text file: ";
    std::cin.get (str,256);    // get c-string

    std::ifstream is(str);     // open file

    char c;
    while (is.get(c))          // loop getting single characters
        std::cout << c;

    is.close();                // close file

    return 0;
}
