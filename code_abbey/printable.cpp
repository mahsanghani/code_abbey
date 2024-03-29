#include <string>
//ASCII printable characters

#include <iostream>
using namespace std;

// ASCII printable characters

class pr_char {
public:
	pr_char(int i = 0) : c(i % 128) { }
	void  print() const { cout << rep[c]; }
private:
	int  c;
	static const char*  rep[128];
};
const char*  pr_char::rep[128] =
{
	"nul", "soh", "stx", "etx", "eot", "enq", "ack", "bel", "bs",  "ht",
	"nl",  "vt",  "np",  "cr",  "so",  "si",  "dle", "dc1", "dc2", "dc3",
	"dc4", "nak", "syn", "etb",  "can", "em", "sub", "esc", "fs",  "gs",
	"rs", "us", "sp", "!", "\"", "#", "$", "%", "&", "'",
	"(", ")", "*", "+", ",", "-", ".", "/", "0", "1",
	"2", "3", "4", "5", "6", "7", "8", "9", ":", ";",
	"<", "=", ">", "?", "@", "A", "B", "C", "D", "E",
	"F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
	"P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y",
	"Z", "[", "|", "]", "^", "_", "'", "a", "b", "c"
	"d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
	"n", "o", "p", "q", "r", "s", "t", "u", "v", "w",
	"x", "y", "z", "{", "|", "}", "~", "del" };

int main()
{
	pr_char  c;

	for (int i = 0; i < 128; ++i) {
		c = static_cast<pr_char>(i);
		c.print();
		cout << endl;
	}
}