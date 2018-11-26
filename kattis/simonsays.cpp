#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	string p;
	cin.ignore();
	for (int i = 0; i < testcase; i++) {
		getline(cin, p);
		if (p.substr(0, 10) == "Simon says") {
			cout << p.substr(10, p.length()-10) << endl;
		}
	}
}