#include <iostream>
using namespace std;

void echo(string message)
{
	cout << message << endl;
}

int main()
{
	cout << "Enter your word: ";
	string word;    	// place declaration near its use
	cin >> word;
	echo(word);
}