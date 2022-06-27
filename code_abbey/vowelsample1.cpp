#include<iostream>
#include<cstring>
using namespace std;

int vCount(char *);

int main() {

	char word[80];
	cout << "enter a line:";
	cin.getline(word, 80);
	cout << "vowel count: " << vCount(word) << endl;

	return 0;
}

// returns the number of vowels in a char array
int vCount(char * pCh) {
	int vowels = 0;

	while (*pCh) {
		if (strspn(pCh, "aeiouAEIOU"))
			vowels++;
		pCh++;
	}

	return vowels;
}

/*
sample output:
enter a line: count the vowels in this sentence
vowel count: 10

*/