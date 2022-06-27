#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int sizeHRML, sizeQuery;
	cin >> sizeHRML >> sizeQuery;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string s;
	map<string, string> mp;
	vector<string> tags;
	for (int i = 0; i < sizeHRML; i++) {

		cin >> s;

		if (s[0] == '<' && s[1] != '/') {
			bool tagClosed = (s[s.size() - 1] == '>');
			string tagName = tagClosed ? string(s.begin() + 1, s.end() - 1) : string(s.begin() + 1, s.end());
			if (tags.size()) {
				tags.push_back(tags[tags.size() - 1] + "." + tagName);
			}
			else {
				tags.push_back(tagName);
			}

			string attr_name, delim, value;

			while (!tagClosed) {
				cin >> attr_name >> delim >> value;
				if (value[value.size() - 1] == '>') {
					value = string(value.begin() + 1, value.end() - 2);
					tagClosed = true;
				}
				else {
					value = string(value.begin() + 1, value.end() - 1);
				}
				mp[tags[tags.size() - 1] + "~" + attr_name] = value;
			}
		}

		else if (s[0] == '<' && s[1] == '/') {
			tags.pop_back();
		}
	}

	string query;
	for (int i = 0; i < sizeQuery; i++) {
		cin >> query;
		if (mp.find(query) != mp.end()) {
			cout << mp[query] << endl;
		}
		else {
			cout << "Not Found!" << endl;
		}
	}

	return 0;
}