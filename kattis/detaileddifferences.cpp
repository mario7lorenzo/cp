#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		string first, second;
		cin >> first;
		cin >> second;
		cout << first << endl;
		cout << second << endl;
		for (int j = 0; j < first.length(); j++) {
			if (first[j] == second[j]) {
				cout << '.';
			}
			else {
				cout << '*';
			}
		}
		cout << endl;
	}
}