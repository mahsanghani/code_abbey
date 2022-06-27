#include <string>
#include <iostream>
using namespace std;

class customer {
public:
	enum c_kind { general, wholesale, retail };
	void  set_name(const string& l, const string& f)
	{
		last_name = l; first_name = f;
	}
	c_kind  get_kind() const { return t; }
	void  set_kind(c_kind k) { t = k; }
	void  print() const {
		cout << (first_name + "  "
			+ last_name) << endl;
	}
	double price_discount() const;
private:
	string  last_name, first_name;
	int  id_number;
	c_kind  t;
};

double customer::price_discount() const
{
	if (t == wholesale)
		return 0.20;
	else
		return 0.1;
}

int main()
{
	customer c, d;

	c.set_name("Pohl", "Ira");
	c.set_kind(c.wholesale);
	c.print();
	cout << "\nYour PC costs "
		<< 900 * (1 - c.price_discount())
		<< " dollars." << endl;
}