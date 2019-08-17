#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
using namespace std;

struct operation
{
	char op;
	int dig;
};

vector<operation> input(int &m, int &init)
{
	int n;
	operation an_op;
	vector<operation> all_ops;

	cout << "input data:" << endl;
	cin >> init;

	for(;;)
	{
		cin >> an_op.op;

		if (an_op.op == 'e')
		{
			break;
		}

		cin >> an_op.dig;

		if ('%' == an_op.op)
		{
			m = an_op.dig;
		}

		all_ops.push_back(an_op);
	}

	return all_ops;
}

int process(int &m, int &init, vector<operation> data)
{
	int r = 0;
	int a = init;
	for (int i = 0; i < data.size(); i++)
	{
		if ('+' == data[i].op)
		{
			a += data[i].dig;
		}
		else if('*' == data[i].op)
		{
			a *= data[i].dig;
		}

		a = a % m;

		if ('%' == data[i].op)
		{
			r = a;
		}
	}
	return r;
}

void output(int remainder)
{
	cout << "answer:" << endl;
	cout << remainder << endl;
}

int main(void)
{
	int m, init;
	auto data = input(m,init);
	auto remainder = process(m, init, data);
	output(remainder);

	return 0;
}