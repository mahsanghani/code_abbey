#include <limits>
#include <iostream>
#include <unordered_map>
#include <stack>
#include <iterator>

using namespace std;

class HRMLParser {
public:
	void Push(const string& line) {
		if (line[1] == '/') {
			m_tag_path.erase(m_delim_pos.top());
			m_delim_pos.pop();
			return;
		}
		auto itr = line.cbegin();
		auto tag_name_begin = ++itr;
		while (*++itr != ' ' && *itr != '>');
		string tag_name(tag_name_begin, itr);
		if (m_delim_pos.empty()) {
			m_delim_pos.push(0);
		}
		else {
			m_delim_pos.push(m_tag_path.size());
			m_tag_path.append(".");
		}
		m_tag_path.append(tag_name);
		while (*itr == ' ') {
			auto attr_name_begin = ++itr;
			while (*++itr != ' ');
			string attr_name(attr_name_begin, itr);
			advance(itr, 4);
			auto value_begin = itr;
			while (*++itr != '"');
			string value(value_begin, itr);
			m_attrs[m_tag_path + "~" + attr_name] = move(value);
			++itr;
		}
	}

	unordered_map<string, string>&& Finish() {
		return move(m_attrs);
	}
private:
	string m_tag_path;
	stack<size_t> m_delim_pos;
	unordered_map<string, string> m_attrs;
};

int main() {
	int N;
	int Q;
	cin >> N;
	cin >> Q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	HRMLParser parser;
	for (int i = 0; i < N; ++i) {
		string line;
		getline(cin, line);
		parser.Push(line);
	}
	unordered_map<string, string> attrs = parser.Finish();
	for (int i = 0; i < Q; ++i) {
		string line;
		getline(cin, line);
		auto attr_itr = attrs.find(line);
		if (attr_itr == attrs.cend()) {
			cout << "Not Found!" << endl;
		}
		else {
			cout << attr_itr->second << endl;
		}
	}
	return 0;
}