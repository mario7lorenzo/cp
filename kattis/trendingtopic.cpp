#include <bits/stdc++.h>
using namespace std;

int main() {
	string op;
	bool isfirst = true;
	queue<vector<string>> q;
	while (getline(cin, op)) {
		if (op == "<text>") {
			string txt;
			vector<string> aux;
			while (cin >> txt, txt != "</text>") {
				aux.push_back(txt);
			}
			if (q.size() == 7) {
				q.pop();
			}
			q.push(aux);
		}
		else if (op == "") {
			continue;
		}
		else if (op.substr(0, 4) == "<top") {
			unordered_map<string, int> help;
			map<int, set<string>> fin;
			int many;
			string temp = "";
			for (int i = 5; i < op.length(); i++) {
				if (op[i] == ' ') {
					many = stoi(temp);
					break;
				}
				else {
					temp += op[i];
				}
			}
			int maxi = -1e9;
			for (int i = 0; i < q.size(); i++) {
				vector<string> tex = q.front();
				q.pop();
				q.push(tex);
				for (int j = 0; j < tex.size(); j++) {
					if (tex[j].length() >= 4) {
						help[tex[j]]++;
						maxi = max(maxi, help[tex[j]]);
					}
				}
			}
			unordered_map<string, int>::iterator itr;
			for (itr = help.begin(); itr != help.end(); itr++) {
				int freq = itr->second;
				string let = itr->first;
				fin[freq].insert(let);
			} 
			int news = 0;
			cout << "<top " << many << '>' << endl;
			while (news < many) {
				set<string> temp = fin[maxi];
				for (auto i : temp) {
					cout << i << ' ' << maxi << endl;
				}
				maxi--;
				news += temp.size();
			}
			cout << "</top>" << endl;
		}
	}
}