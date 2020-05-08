#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	bool isfirst = true;
	for (int i = 0; i < testcase; i++) {
		if (isfirst) {
			cin.ignore();
			isfirst = false;
		}
		string p;
		getline(cin, p);
		if (p.substr(0, 11) == "simon says ") {
			cout << p.substr(11) << endl;
		}
		else {
			cout << endl;
		}
	}
}