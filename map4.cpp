#include <cstdio>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

struct tagobj {
	string name;
	map<string, tagobj*> tmap;
	map<string, string> map_att;
	tagobj* prev = NULL;
};

void delete_tags(tagobj* tag) {
	for (map<string, tagobj*>::iterator i = tag->tmap.begin(); i != tag->tmap.end(); i++) {
		delete_tags(i->second);
	}
	delete(tag);
}

int main() {
	//Setup a vector holding all first level tags
	map<string, tagobj*> main;
	//Current depth so as to nest
	tagobj* masterTag = NULL;

	int tlines, qlines;
	string ints;
	getline(cin, ints);
	stringstream ss(ints);
	ss >> tlines;
	ss >> qlines;

	string line;
	size_t del_tag;
	//Save the information 
	for (int i = 0; i < tlines; i++) {
		//Get Tag from line
		getline(cin, line);
		del_tag = line.find_first_of(" >");
		string tag = line.substr(1, del_tag - 1);
		//opening tags
		if (tag[0] != '/') {
			//Create Struct
			tagobj* currTag = new tagobj();
			currTag->prev = masterTag;
			currTag->name = tag;
			//check if we add to master vector or previous:
			if (!masterTag) {
				main[currTag->name] = currTag;
			}
			else {
				masterTag->tmap[currTag->name] = currTag;
			}
			masterTag = currTag;
			//Add all attributes
			size_t found = line.find("=", del_tag);
			while (found != string::npos) {
				//Get the attribute
				string name = line.substr(del_tag + 1, found - del_tag - 2);
				//move past the =
				del_tag = found + 2;
				found = line.find("\"", del_tag + 1);
				//Copy the value
				string value = line.substr(del_tag + 1, found - del_tag - 1);
				//add to map
				currTag->map_att[name] = value;
				//keep going
				del_tag = line.find(" ", found);
				found = line.find("=", found);
			}
		}
		else {
			//If its a closing Tag return main tag to its previous
			masterTag = masterTag->prev;
		}
	}

	for (int i = 0; i < qlines; i++) {
		tagobj* masterq = NULL;
		getline(cin, line);
		size_t start = 0;
		string val;
		bool fnd;
		while (true) {
			size_t found = line.find_first_of(".~", start);
			string buff = line.substr(start, found - start);
			fnd = false;
			//looking for attribute
			if (start > 0 && line[start - 1] == '~') {
				//Attributes have a sentinal
				//Check for bad input
				if (masterq) {
					val = masterq->map_att[buff];
					if (!val.empty()) {
						fnd = true;
					}
					break;
				}
			}
			else {
				//Looking for a tag, if found, continue looking
				map<string, tagobj*> *bufobj = NULL;
				//Make sure to look in right place
				if (masterq) {
					bufobj = &(masterq->tmap);
				}
				else {
					bufobj = &main;
				}
				tagobj* frommap = (*bufobj)[buff];
				if (frommap) {
					masterq = frommap;
				}
				else {
					break;
				}
			}
			start = found + 1;
		}
		//Printing Time:
		if (fnd) {
			cout << val << endl;
		}
		else {
			cout << "Not Found!" << endl;
		}
	}
	for (map<string, tagobj*>::iterator i = main.begin(); i != main.end(); i++) {
		delete_tags(i->second);
	}
}