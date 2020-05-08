#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	map<char, int> saver;
	bool isfirst = true;
	for (int i = 0; i < testcase; i++) {
		if (isfirst) {
			cin.ignore();
			isfirst = false;
		}
		string p;
		getline(cin, p);
		for (int i = 0; i < p.length(); i++) {
			int val = int(p[i]);
			if (val < 97) {
				val += 32;
			}
			if (val >= 97 && val <= 122) {
				saver[char(val)]++;
			}
		}
		string misslst = "";
		bool miss = false;
		for (int i = 97; i < 123; i++) {
			if (saver[char(i)] == 0) {
				miss = true;
				misslst += char(i);
			}
		}
		if (!miss) {
			cout << "pangram" << endl;
		}
		else {
			cout << "missing " << misslst << endl;
		}
		saver.clear();
	}
}