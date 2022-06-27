#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <bits/stdc++.h> 
using namespace std;

struct parsed_line {
public:
	// tag label
	string label_;
	// attribute list
	unordered_map<string, string> attributes;
	// thing to store string stream
	vector<string> segments;

	parsed_line(string &inp_line) {
		// drop <>
		string line = inp_line.substr(1, inp_line.size() - 2);
		//open string stream
		stringstream parse(line);
		// store intermediate
		string intermediate;

		// split on spaces
		while (getline(parse, intermediate, ' ')) {
			// ignore equals
			if (intermediate != "=") {
				// add to list
				segments.push_back(intermediate);
			}
		}
		// get label as first list
		label_ = segments[0];

		// process attributes - probably can merge with above loop in a clever way to save lines
		for (int i = 1; i < segments.size(); i += 2) {
			int len = segments[i + 1].size();
			// put rest in hash table
			attributes[segments[i]] = segments[i + 1].substr(1, len - 2);
		}
	}
};

// string concatenation - can be quite slow, would refactor
string unfold_address(vector<string> &vec) {
	string out = "";
	for (auto &el : vec) {
		out += el + ".";
	}
	return out.substr(0, out.size() - 1);
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n_lines, n_queries;
	cin >> n_lines;
	cin >> n_queries;

	vector<string> address; // use a vector as a stack which keeps track of history 
	unordered_map<string, unordered_map<string, string > > text; // is the thing to be queried

	cin.ignore();
	string line;
	for (int i = 0; i < n_lines; i++) {
		getline(cin, line);
		if (line[1] == '/') { // if it is a closing tag just pop back and do nothing (assuming input is valid!)
			address.pop_back();
		}
		else {
			auto temp = parsed_line(line); // otherwise, parse the line and add to address
			address.push_back(temp.label_);
			text[unfold_address(address)] = temp.attributes; // store result

		}
	}

	// now loop over queries and print out results
	for (int i = 0; i < n_queries; i++) {
		string line;
		getline(cin, line);
		int att_pos = line.find('~');
		string addy = line.substr(0, att_pos);
		string query = line.substr(att_pos + 1, line.size() - att_pos - 1);
		if (text.find(addy) == text.end()) {
			cout << "Not Found!" << endl;
		}
		else {
			if (text[addy].find(query) == text[addy].end()) {
				cout << "Not Found!" << endl;
			}
			else {
				cout << text[addy][query] << endl;
			}
		}

	}

	return 0;

}