// For printing out grade meanings
#include <iostream>
using namespace std;
int main()
{
	int grade; // from 0 to 100
	char letter_grade = 'Z'; // A, B, C, D, F, or Z
	cout << "Enter Your Number Score:" << endl;
	cin >> grade;
	if (grade == 100) {
		cout << " First in Class!\n";
		letter_grade = 'A';
	}
	else if (grade >= 90 && grade < 100) {
		cout << " Congratulations!\n";
		letter_grade = 'A';
	}
	else if (grade >= 80 && grade < 90) {
		cout << " Very Good\n";
		letter_grade = 'B';
	}
	
	else if (grade >= 70 && grade < 80) {
		cout << " Okay\n";
		letter_grade = 'C';
	}
	else if (grade >= 60 && grade < 70) {
		cout << " Work harder\n";
		letter_grade = 'D';
	}
	else if (grade >= 0 && grade < 60) {
		cout << " Sorry you failed\n";
		letter_grade = 'F';
	}
	else
		cout << " Not a recognizable grade" << endl;
	cout << " Your grade was " << letter_grade
		<< endl;
}