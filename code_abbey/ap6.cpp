#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>



using namespace std;


int main() {

	int query, tags;
	unordered_map<string, string> map;
	vector<string> v;
	vector<string> tagname;
	cin >> tags >> query;
	cin.ignore();

	std::string app, strind = "", key, subval;

	for (int i = 0; i < tags; i++) {
		std::getline(std::cin, app);
		stringstream ss(app);
		app = "";
		while (ss >> app) {

			if (app.find("=") != string::npos)
				continue;
			else if (app.find("</") != string::npos) {
				app.erase(0, 2);
				app.erase(app.length() - 1, 1);
				size_t start_pos = strind.find(app, 0);
				if (start_pos != 0)
					strind.replace(start_pos - 1, app.length() + 1, "");
				else
					strind.replace(start_pos, app.length() + 1, "");
			}
			else if (app.find("<") != string::npos) {
				if (app.find(">") != string::npos)
					app.replace(app.find(">"), 1, "");
				if (strind.empty())
					strind += app.substr(1);
				else
					strind += "." + app.substr(1);


			}
			else if (app.find("\"") != string::npos) {
				app.erase(0, 1);
				app.erase(app.find("\""));
				//cout<<strind+"~"+subval<<endl;
				map[strind + "~" + subval] = app;

			}

			else
				subval = app;


		}

	}



	for (int i = 0; i < query; i++) {
		std::getline(std::cin, app);

		if (map.find(app) != map.end())
			cout << map[app] << endl;
		else
			cout << "Not Found!" << endl;
	}


	return 0;
}
