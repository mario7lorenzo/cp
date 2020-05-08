#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<char>> lst;
bool available = false;
unordered_map<char, bool> ver;

void specialdfs(char a, char b) {
	ver[a] = false;
	for (int i = 0; i < lst[a].size(); i++) {
		char temp = lst[a][i];
		if (temp == b) {
			available = true;
		}
		else if (ver[temp]) {
			specialdfs(temp, b);
		}
	}
}

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		char a, b;
		cin >> a >> b;
		lst[a].push_back(b);
	}
	for (int i = 0; i < n; i++) {
		string one, two;
		cin >> one >> two;
		bool yes = true;
		if (one.length() != two.length()) {
			yes = false;
		}
		else {
			for (int i = 0; i < one.length(); i++) {
				if (one[i] != two[i]) {
					for (int j = 97; j <= 122; j++) {
						ver[char(j)] = true;
					}
					available = false;
					specialdfs(one[i], two[i]);
					if (!available) {
						yes = false;
						break;
					}
				}
			}
		}
		if (yes) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
}