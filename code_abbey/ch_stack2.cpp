#include <iostream>
#include <assert.h>
using namespace std;

#include "ch_stack2.h"

// Count the number of c’s found in s

int cnt_char(char c, ch_stack s)
{
	int  count = 0;

	while (!s.empty())             	// done when empty
		count += (c == s.pop());    	// found a c
	return count;
}

int main()
{

	ch_stack  data;     	//creates data.s[100]
	ch_stack  d[3];     	//creates 3 100 element ch_stacks
	ch_stack  w(4, "ABCD");    	//w.s[0]='A'...w.s[3]='D'
	ch_stack  x(100, "This is a longer string takes up size 100");
	ch_stack  y(x);      // creates stack from x
	data.push('N');
	data.push('O');
	d[2].push('Y');
	data.print();
	d[2].print();
	w.print();
	x.print();
	y.print();
	cout << cnt_char('A', w) << endl;
	cout << cnt_char('s', x) << endl;

}