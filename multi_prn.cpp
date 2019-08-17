#include "pgm.h"
#include <string>
void prn_info(const string& pgm_name)
{
	cout << "Usage: " << pgm_name << endl;
	cout << "This program illustrates a " << endl;
	cout << "program in more than one file." << endl;
	cout << "In this example, a single" << endl;
	cout << ".h file is included at the" << endl;
	cout << "top of our three .cpp files." << endl;
	cout << "Thus pgm.h acts as the \"glue\"" << endl;
	cout << "that binds the program." << endl;
}