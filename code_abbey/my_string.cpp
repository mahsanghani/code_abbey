//Reference counted my_strings with private str_obj members

#include <iostream>
#include <assert.h>
using namespace std;

// Reference counted my_strings

class str_obj {
public:
	friend class my_string;	// my_string access members
	str_obj() : len(0), ref_cnt(1)
	{
		s = new char[1]; assert(s != 0); s[0] = 0;
	}
	str_obj(const char* p) : ref_cnt(1)
	{
		len = strlen(p); s = new char[len + 1];
		assert(s != 0); strcpy(s, p);
	}
	~str_obj() { delete[]s; }
private:
	int    len, ref_cnt;
	char*  s;
};

class my_string {
public:
	my_string() { st = new str_obj; assert(st != 0); }
	my_string(const char* p)
	{
		st = new str_obj(p); assert(st != 0);
	}
	my_string(const my_string& str)
	{
		st = str.st; st->ref_cnt++;
	}
	~my_string();
	void  assign(const my_string& str);
	void  print() const { cout << st->s; }
	my_string& operator=(const my_string& str);
	char& operator[](int position);
private:
	str_obj*  st;
};

my_string::~my_string()
{
	if (--st->ref_cnt == 0)
		delete st;
}

void my_string::assign(const my_string& str)
{
	if (str.st != st) {
		if (--st->ref_cnt == 0)
			delete st;
		st = str.st;
		st->ref_cnt++;
	}
}

my_string& my_string::operator=(const my_string& str)
{
	if (str.st != st) {
		if (--st->ref_cnt == 0)
			delete st;
		st = str.st;
		st->ref_cnt++;
	}
	return *this;
}

char& my_string::operator[](int position)
{
	char* s = st->s;
	for (int i = 0; i != position; ++i) {
		if (*s == 0)
			break;
		s++;
	}
	return *s;
}

int main()
{
	//code fragment using overloaded assignment
	my_string  a, b("do "), c("do not "), d, e("1234567890");

	a = b;             	//a is now "do "
	d = b = c;         	//these are "do not "
	c = "do not but "; 	//invoke conversion constructor
	d.assign(c);
	a.print();
	b.print();
	c.print();
	d.print();
	cout << e[4] << endl;
}