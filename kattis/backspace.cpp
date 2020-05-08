#include <bits/stdc++.h>
using namespace std;

int main() {
	string txt;
	cin >> txt;
	vector<string> lst;
	int counter = 0;
	for (int i = 0; i < txt.length(); i++) {
		if (txt.substr(i, 1) != "<") {
			lst.push_back(txt.substr(i, 1));
		}
		else {
			lst.erase(lst.end());
		}
	}
	for (int i = 0; i < lst.size(); i++) {
		if (lst[i] == " ") {
			continue;
		}
		else {
			cout << lst[i];
		}
	}
	cout << endl;
}