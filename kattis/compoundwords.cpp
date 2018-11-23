#include <bits/stdc++.h>
using namespace std;
bool checker(string x, set<string> k) {
	if (k.find(x) == k.end()) return false;
	else return true;
}

int main() {
	string p;
	vector<string> wordlst;
	set<string> final;
	while (getline(cin, p)) {
		string keysaver = "";
		for (int i = 0; i < p.length(); i++) {
			if (p[i] != ' ') {
				keysaver += p[i];
			}
			else {
				wordlst.push_back(keysaver);
				keysaver = "";
			}
		}
		wordlst.push_back(keysaver);
		
	}
	for (int i = 0; i < wordlst.size(); i++) {
		for (int j = i+1; j < wordlst.size(); j++) {
			string temp;
			temp = wordlst[i] + wordlst[j];
			if (checker(temp, final) == false) {
				final.insert(temp);
			}
			temp = wordlst[j] + wordlst[i];
			if (checker(temp, final) == false) {
				final.insert(temp);
			}
		}
	}
	set<string>::iterator itr;
	for (itr = final.begin(); itr != final.end(); itr++) {
		cout << *itr << endl;
	}
}