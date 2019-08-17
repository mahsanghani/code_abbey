// String function implementations

#include <iostream>
using namespace std;

size_t strlen2(const char* s)
{
	int  i;
	for (i = 0; s[i] != '\0'; ++i)
		continue;
	return i;
}

int strcmp(const char* s1, const char* s2)
{
	int  i;
	for (i = 0; s1[i] && s2[i] && (s1[i] == s2[i]); ++i)
		continue;
	return (s1[i] - s2[i]);
}

char* strcpy(char* s1, const char* s2)
{
	for (int i = 0; s1[i] = s2[i]; ++i)
		continue;
	return s1;
}

bool streq1(const char* s1, const char* s2)
{
	while (*s1 != 0 && *s2 != 0)
		if (*s1++ != *s2++)
			return false;
	return (*s1 == *s2);
}

bool streq2(const char s1[], const char s2[])
{
	int  i;

	for (i = 0; (s1[i] != 0) && (s2[i] != 0); ++i)
		if (s1[i] != s2[i])
			return false;
	return (s1[i] == s2[i]);
}

// Recursive string function implementations

size_t strlen1(const char* s)
{
	if (*s == '\0')
		return 0;      	// the end
	else              	// add 1 and recur on the rest
		return (1 + strlen1(s + 1));
}

int main()
{
	const char* a = "This is first string!";
	const char* b = "This is second string!";

	cout << "\n string 1 is " << strlen1(a) << " characters long" <<
		" and is " << a << endl;
	cout << "\n string 2 is " << strlen2(b) << " characters long" <<
		" and is " << b << endl;

	cout << "\nStrings 1 and 2 streq1 is " << streq1(a, b) << endl;
	cout << "\nStrings 1 and 2 streq2 is " << streq2(b, a) << endl;

	cout << "\nStrings 1 and 2 strcmp is " << strcmp(a, b) << endl;
	strcpy(b, a);
	cout << "\n string 1 is " << strlen1(a) << " characters long" <<
		" and is " << a << endl;
	cout << "\n string 2 is " << strlen2(b) << " characters long" <<
		" and is " << b << endl;
}