#include <iostream>
using namespace std;

enum week { sun, mon, tues, weds, thurs, fri, sat };

static union {
	int   i;
	week  w;
};

int main()
{
	i = 5;
	w = sat;

	if (w == sat || w == sun)
		cout << " It's the weekend! \n";
}