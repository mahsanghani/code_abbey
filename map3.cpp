#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

int search_for_tag(size_t start, string s_end, vector<string> &vec, string needle) {
	int curr = start;
	int end = vec.size();
	string endcur;
	char buff[200];
	while (true) {
		if (vec[curr][0] == '|') {
			//see if its the one
			if (!vec[curr].compare(needle)) {
				return curr;
				//see if its the end
			}
			else if (!vec[curr].compare(s_end)) {
				return -1;
				//pass this tag
			}
			else {
				vec[curr].copy(buff, vec[curr].size(), 0);
				buff[vec[curr].size()] = '\0';
				endcur = "|" + string(buff);
				endcur.replace(1, 1, "/");
				while (vec[curr].compare(endcur)) {
					curr++;
				}
				curr++;
				if (curr == end) return -1;
			}
		}
		else {
			while (vec[curr][0] != '|') {
				curr++;
			}
		}
	}
}

int search_for_att(size_t start, string s_end, vector<string> &vec, string needle) {
	int curr = start;
	while (vec[curr][0] != '|') {
		if (!vec[curr].compare(needle)) {
			return curr;
		}
		curr++;
		if (curr == vec.size()) return -1;
	}
	return -1;
}

int main() {
	int tlines, qlines;
	string ints;
	getline(cin, ints);
	stringstream ss(ints);
	ss >> tlines;
	ss >> qlines;

	string line;
	char buf[200];
	size_t del_tag;
	vector<string> contain;
	//Parse the shenanigans
	for (int i = 0; i < tlines; i++) {
		getline(cin, line);
		del_tag = line.find_first_of(" >");
		//Get Tag
		line.copy(buf, del_tag - 1, 1);
		buf[del_tag - 1] = '\0';
		string tagbuf(buf);
		tagbuf = "|" + tagbuf;
		contain.push_back(tagbuf);
		size_t found = line.find("=", del_tag);
		while (found != string::npos) {
			//Get the attribute
			line.copy(buf, found - del_tag - 2, del_tag + 1);
			buf[found - del_tag - 2] = '\0';
			string attbuf(buf);
			contain.push_back(attbuf);
			//move past the =
			del_tag = found + 2;
			found = line.find("\"", del_tag + 1);
			//Copy the value
			line.copy(buf, found - del_tag - 1, del_tag + 1);
			buf[found - del_tag - 1] = '\0';
			string valbuf(buf);
			contain.push_back(valbuf);
			del_tag = line.find(" ", found);
			found = line.find("=", found);
		}
	}
	//Query Time   
	for (int i = 0; i < qlines; i++) {
		size_t startString = 0;
		bool typeTag = true;
		size_t startVec = 0;
		string endVec = "";
		bool notFound = true;
		string attval;
		string line;
		getline(cin, line);
		while (true) {
			//Get next token
			size_t found = line.find_first_of(".~", startString);
			if (found == string::npos) found = line.size();
			line.copy(buf, found - startString, startString);
			buf[found - startString] = '\0';
			string tagbuf(buf);

			//Check if its a Tag
			if (startString > 0 && line[startString - 1] == '~') {
				typeTag = false;
			}
			else {
				tagbuf = "|" + tagbuf;
			}
			//Find a tag
			if (typeTag) {
				int res = search_for_tag(startVec, endVec, contain, tagbuf);
				if (res < 0) {
					break;
				}
				else {
					startVec = res + 1;
					endVec = "|" + tagbuf;
					endVec.replace(1, 1, "/");
					startString = found + 1;
				}
			}
			else {
				//Find an attibute
				int res = search_for_att(startVec, endVec, contain, tagbuf);
				if (res >= 0) {
					attval = contain[res + 1];
					notFound = false;
				}
				break;
			}
		}
		//Printing
		if (notFound) {
			cout << "Not Found!" << endl;
		}
		else {
			cout << attval << endl;
		}
	}
	return 0;
}