#include <iostream>
#include <string>
using namespace std;

// Class with mutable members

class person {
public:
	person(const string namep, int agep,
		unsigned long ssn)
		: name(namep), age(agep), soc_sec(ssn) {}
	void  bday() const { ++age; }
	void  print() const
	{
		cout << name << " is " << age
			<< " years old. SSN = "
			<< soc_sec << endl;
	}
private:
	mutable int   age;     	// always modifiable
	const unsigned long  soc_sec;
	const string  name;
};

int main()
{
	const person ira("ira pohl", 38, 1110111);

	ira.print();
	ira.bday();	       // okay, ira.age is mutable
	ira.print();
}