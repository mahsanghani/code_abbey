#include <iostream>
using namespace std;

class my_clock {
public:
	my_clock(unsigned long i = 0);	// ctor & conversion
	my_clock set(unsigned long i = 0);
	void  print() const;         	// formatted printout
	void  tick();           	//add one second
	void  reset(const my_clock& c);
	my_clock operator++() { tick(); return *this; }
	friend my_clock operator*(unsigned long m, my_clock c);
	friend my_clock operator*(my_clock c, unsigned long m);
	my_clock  operator-(my_clock c);

	friend my_clock operator+(my_clock c1,
		my_clock c2);
private:
	unsigned long  tot_secs, secs, mins, hours, days;
};

inline my_clock::my_clock(unsigned long i) :
	tot_secs(i), secs(i % 60),
	mins((i / 60) % 60),
	hours((i / 3600) % 24),
	days(i / 86400) { }


my_clock my_clock::set(unsigned long i)
{
	tot_secs = i;
	secs = i % 60;
	mins = (i / 60) % 60;
	hours = (i / 3600) % 24;
	days = i / 86400;
	return *this;
}

void my_clock::tick()
{
	*this = static_cast<my_clock>(++tot_secs);
}

my_clock my_clock::operator-(my_clock c)
{
	return (tot_secs - c.tot_secs);
}

void my_clock::print() const
{
	cout << days << " d :" << hours << " h :"
		<< mins << " m :" << secs << " s" << endl;
}

void my_clock::reset(const my_clock& c)
{
	tot_secs = c.tot_secs;
	secs = c.secs;
	mins = c.mins;
	hours = c.hours;
	days = c.days;
}


my_clock operator+(my_clock c1, my_clock c2)
{
	return (c1.tot_secs + c2.tot_secs);
}

my_clock operator*(unsigned long m, my_clock c)
{
	return (m * c.tot_secs);
}

my_clock operator*(my_clock c, unsigned long m)
{
	return (m * c);
}

//alternative method for ++ (use one or the other, but not both)
// my_clock operator++(my_clock& cl) { cl.tick(); return cl; }


//my_clock and overloaded operators

int main()
{
	my_clock  t1(59), t2(172799); 	// t2=2 days-1 sec

	my_clock  c1(900), c2(400);


	cout << "initial times are" << endl;
	t1.print();
	t2.print();
	++t1; 	// invokes the overloaded member function
	++t2;
	cout << "after one second times are" << endl;
	t1.print();
	t2.print();


	cout << "c1 and c2 before reset" << endl;
	c1.print();
	c2.print();

	c1.reset(c2);
	c2.reset(100);
	cout << "c1 and c2 after reset" << endl;
	c1.print();
	c2.print();

	t1.set(179);
	c1 = t1 + t2;
	c2 = 3 * t2;
	t2 = c2 - t2;
	c2 = t2 * 2;   //multiply again

	cout << "c1 c2 t1 after + * - " << endl;
	c1.print();
	c2.print();
	t2.print();

}