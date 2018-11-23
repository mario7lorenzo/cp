#include <bits/stdc++.h>
using namespace std;

int main() {
	int ja, ji;
	while (cin >> ja >> ji, (ja != 0 && ji != 0)) {
		unordered_set<int> mapp;
		int counter = 0;
		for (int i = 0; i < ja; i++) {
			int x;
			cin >> x;
			mapp.insert(x);
		}
		for (int i = 0; i < ji; i++) {
			int x;
			cin >> x;
			if (mapp.find(x) != mapp.end()) {
				counter++;
			}
		}
		cout << counter << endl;
	}
}