#include <iostream>
#include <assert.h>
using namespace std;

struct slistelem {
	char        data;
	slistelem*  next;
};
class slist {               	// singly linked list
public:
	slist() : h(0) { }       	// 0 denotes empty slist
	~slist();
	void  prepend(char c);   	// adds to front of slist
	void  del();
	slistelem*  first() const { return h; }
	void  print() const;
	void  release();
private:
	slistelem*  h;           	// head of slist
};

void slist::prepend(char c)
{
	slistelem*  temp = new slistelem;	// create element
	assert(temp != 0);
	temp->next = h;                	// link to slist
	temp->data = c;
	h = temp;                  	// update head of slist
}

void slist::del()
{
	slistelem*  temp = h;
	h = h->next;         	// presumes nonempty slist
	delete temp;
}


void slist::print() const      	// object is unchanged
{
	slistelem*  temp = h;

	while (temp != 0) {         	// detect end of slist
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "\n###" << endl;
}
// Elements returned to the heap

void slist::release()
{
	while (h != 0)
		del();
}

slist::~slist()
{
	cout << "destructor invoked" << endl;
	release();
}

int main()
{
	slist*  p;
	{
		slist  w;

		w.prepend('A');
		w.prepend('B');
		w.print();
		w.del();
		w.print();
		p = &w;
		p->print();
		cout << "exiting inner block" << endl;
	}
	// p -> print();  gives system-dependent behavior
	cout << "exiting outer block" << endl;
}