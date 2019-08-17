#include <iostream>
#include <string>
using namespace std;

class address {
public:
	address(string street, string city)
		:street_name(street), city_name(city) { }
	void   print() const;
	string get_street() const { return street_name; }
	string get_city() const { return city_name; }
private:
	string city_name;
	string street_name;
};

void address::print() const
{
	cout << "\n" << street_name << endl << city_name << endl;
}

class person {
public:
	person(string n, address h);
	void print() const;
	void set_address();
private:
	address home;
	const string name;
};

person::person(string n, address h) : name(n), home(h) { }

void person::print() const
{
	cout << "\nName is " << name << endl;
	home.print();
}


int main()
{
	const person ira(string("ira pohl"), address("600 Dreamy Lane", "Santa Cruz"));
	ira.print();
}
