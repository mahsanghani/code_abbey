#include <iostream>
using namespace std;
void echo(const string message)
{
	cout << message << endl;
}
int main()
{
	string word;
	cout << "Enter your word: ";
	cin >> word; // reads to white space
	echo(word);
}
// doesn't recognize << and >>