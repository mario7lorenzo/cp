#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<char> lst;
	string p;
	cin >> p;
	for (int i = 0; i < p.length(); i++) {
		if (i == 0) {
			lst.push_back(p[i]);
		}
		else {
			if (lst[lst.size() - 1] == p[i]) {
				continue;
			}
			else {
				lst.push_back(p[i]);
			}
		}
	}
	for (int i = 0; i < lst.size(); i++) {
		printf("%c", lst[i]);
	}
	cout << endl;
}