#include <iostream>
using namespace std;

class ch_stack {
public:
	void  reset() { top = EMPTY; }
	void  push(char c) { s[++top] = c; }
	char  pop() { return s[top--]; }
	char  top_of() const { return s[top]; }
	bool  empty() const { return (top == EMPTY); }
	bool  full() const { return (top == FULL); }
private:
	enum {
		max_len = 100, EMPTY = -1,
		FULL = max_len - 1
	};
	char  s[max_len];
	int   top;
};

// Reverse a string with a ch_stack

int main()
{
	ch_stack  s;
	char   str[40] = { "My name is Don Knuth!" };
	int    i = 0;

	cout << str << endl;
	s.reset();            	// s.top = EMPTY; is illegal
	while (str[i] && !s.full())
		s.push(str[i++]);
	while (!s.empty())    	// print the reverse
		cout << s.pop();
	cout << endl;
}