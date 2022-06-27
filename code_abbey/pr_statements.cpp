#include <iostream>
using namespace std;


// Print a string with a line number 

void pr_numbered_statement(const string& statement)
{
	static int ln = 0;

	ln++;          	// start the line numbers at 1
	cout << "line " << ln << ":" + statement + "\n";
}

// Test pr_numbered_statement() using two strings

int main()
{
	string s1, s2;

	cout << "Enter two words: " << endl;
	cin >> s1 >> s2;
	pr_numbered_statement(s1);
	pr_numbered_statement(s2);
	cout << endl;
}