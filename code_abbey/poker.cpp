#include <iostream>
#include <ctime>     // needed for time()
#include <cstdlib>   // needed for rand() and srand()
using namespace std;


enum suit { clubs, diamonds, hearts, spades };
class pips {
public:
	void  set_pips(int n) { p = n % 13 + 1; }
	int   get_pips() const { return p; }
	void  pr_pips() const { cout << p; }
private:
	int  p;          	// meant to hold values [1,13]
};
class card {
public:
	void  set_card(int n)
	{
		s = static_cast<suit>(n / 13); p.set_pips(n);
	}
	void  pr_card() const;
	suit  get_suit() const { return s; }
	pips  get_pips() const { return p; }
private:
	suit  s;
	pips  p;
};

class deck {
public:
	void  set_deck();
	void  shuffle();
	void  deal(int, int, card*);
	void  pr_deck() const;
private:
	card  d[52];
};

void deck::set_deck()
{
	for (int i = 0; i < 52; ++i)
		d[i].set_card(i);
}

void  deck::shuffle()
{
	for (int i = 0; i < 52; ++i) {
		int  k = i + (rand() % (52 - i));
		card  t = d[i];               	// swap cards
		d[i] = d[k];
		d[k] = t;
	}
}

void deck::deal(int n, int pos, card* hand)
{
	for (int i = pos; i < pos + n; ++i)
		hand[i - pos] = d[i];
}


int main()
{
	card one_hand[9]; 	// max hand is 9 cards
	deck dk;
	int  i, j, k, flush_count = 0, sval[4];
	int  ndeal, nc, nhand;
	do {
		cout << "\nEnter no. cards in a hand (5-9): ";
		cin >> nc;
	} while (nc < 5 || nc > 9);
	nhand = 52 / nc;
	cout << "Enter no. of hands to deal: ";
	cin >> ndeal;
	srand(time(NULL));      	// seed rand() from time()
	dk.set_deck();
	for (k = 0; k < ndeal; k += nhand) {
		if ((nhand + k) > ndeal)
			nhand = ndeal - k;
		dk.shuffle();
		for (i = 0; i < nc * nhand; i += nc) {
			for (j = 0; j < 4; ++j)	// zero suit counts
				sval[j] = 0;
			dk.deal(nc, i, one_hand); 	// deal next hand
			for (j = 0; j < nc; ++j)
				sval[one_hand[j].get_suit()]++;	// +1 to suit
			for (j = 0; j < 4; ++j)
				if (sval[j] >= 5)      	// 5 or more is flush
					flush_count++;
		}
	}
	cout << "\nIn " << ndeal << " ";
	cout << nc << "-card hands there were ";
	cout << flush_count << " flushes\n";
}