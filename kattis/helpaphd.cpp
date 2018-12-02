#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	bool isfirst = true;
	for (int i = 0; i < testcase; i++) {
		string p;
		if (isfirst) {
			cin.ignore();
		}
		cin >> p;
		if (p == "P=NP") {
			cout << "skipped" << endl;
		}
		else {
			int a, b;
			string temp;
			for (int j = 0; j < p.length(); j++) {
				if (p[j] == '+') {
					a = stoi(temp);
					temp = "";
				}
				else {
					temp += p[j];
				}
			}
			b = stoi(temp);
			cout << a+b << endl;
		}
	}
}