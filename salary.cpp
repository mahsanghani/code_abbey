#include <iostream>
using namespace std;

// Calculate salary using static members

class salary {
public:
	void  set(int b) { b_sal = b; your_bonus = 0; }
	void  calc_bonus(double perc)
	{
		your_bonus = b_sal * perc;
	}
	static void  set_all_bonus(int p)
	{
		all_bonus = p;
	}
	int  comp_tot() const
	{
		return (b_sal + your_bonus + all_bonus);
	}
private:
	int         b_sal;
	int         your_bonus;
	static int  all_bonus;     	// declaration
};

// declaration and definition
int salary::all_bonus = 100;

int main()
{
	salary  w1, w2;

	w1.set(1000);
	w2.set(2000);
	w1.calc_bonus(0.2);
	w2.calc_bonus(0.15);
	salary::set_all_bonus(400);
	cout << " w1 " << w1.comp_tot() << "   w2 "
		<< w2.comp_tot() << endl;
}