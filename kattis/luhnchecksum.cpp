#include <bits/stdc++.h>
using namespace std;
int merger(int x) {
	string y;
	y = to_string(x);
	while (y.length() > 1) {
		int counter = 0;
		for (int i = 1; i < y.length(); i++) {
			counter += stoi(y.substr(i-1, 1)) + stoi(y.substr(i, 1));
		}
		y = to_string(counter);
	}
	return stoi(y);
}

int main() {
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		string n;
		cin >> n;
		int counter = 0;
		for (int j = 0; j < n.length(); j++) {
			int k;
			if (j%2) {
				k = 2 * stoi(n.substr(n.length()-1-j, 1));
			}
			else {
				k = stoi(n.substr(n.length()-1-j, 1));
			}
			counter += merger(k);
		}
		if (counter%10) {
			cout << "FAIL" << endl;
		}
		else {
			cout << "PASS" << endl;
		}
	}
}