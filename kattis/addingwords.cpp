#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<string, int> strdef;
	unordered_map<int, string> intdef;
	string p;
	while(getline(cin, p)) {
		if (p.substr(0, 5) == "clear") {
			strdef.clear();
			intdef.clear();
		}
		else if (p.substr(0, 3) == "def") {
			string words = "";
			string temp = "";
			for (int i = 4; i < p.length(); i++) {
				if (p[i] == ' ') {
					words = temp;
					temp = "";
				}
				else {
					temp += p[i];
				}
			}
			int val = stoi(temp);
			if (strdef.find(words) != strdef.end()) {
				intdef.erase(strdef[words]);
			}
			strdef[words] = val;
			intdef[val] = words;
		}
		else if (p.substr(0, 4) == "calc") {
			string slicer = p.substr(5);
			bool isfirst = true;
			bool op = false;
			string temp = "";
			string tempop = "+";
			vector<pair<string, string>> saver;
			int total = 0;
			for (int i = 5;  i < p.length()-2; i++) {
				if (p[i] == ' ') {
					if (op) {
						op = !op;
					}
					else {
						saver.emplace_back(tempop, temp);
						temp = "";
						tempop = "";
						op = !op;
					}
				}
				else {
					if (op) {
						tempop += p[i];
					}
					else {
						temp += p[i];
					}
				}
			}
			saver.emplace_back(tempop, temp);
			bool corr = true;
			for (int i = 0; i < saver.size(); i++) {
				if (strdef.find(saver[i].second) == strdef.end()) {
					corr = false;
					break;
				}
				else if (saver[i].first == "+") {
					total += strdef[saver[i].second];
				}
				else if (saver[i].first == "-") {
					total -= strdef[saver[i].second];
				}
			}
			if (intdef.find(total) == intdef.end()) {
				corr = false;
			}
			if (corr) {
				cout << slicer << ' ' << intdef[total] << endl;
			}
			else {
				cout << slicer << ' ' << "unknown" << endl;
			}
		}
	}
}