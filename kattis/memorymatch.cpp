#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	unordered_map<string, unordered_set<int>> saver;
	int pict = n/2, solved = 0, tbsolve = 0, oneknown;
	for (int i = 0; i < k; i++) {
		int a, b;
		string card1, card2;
		cin >> a >> b >> card1 >> card2;
		if (card1 == card2) {
			if (saver.find(card1) != saver.end()) {
				saver.erase(card1);
			}
			solved++;
		}
		else {

			saver[card1].insert(a);
			saver[card2].insert(b);
		}
	}
	unordered_map<string, unordered_set<int>>::iterator i;
	for (i = saver.begin(); i != saver.end(); i++) {
		if (i->second.size() == 2) {
			tbsolve++;
		}
	}
	oneknown = saver.size()-tbsolve;
	if (n == 2 && k == 0) {
		cout << 1 << endl;
	}
	else {	
		if (oneknown == pict-solved-tbsolve) {
			tbsolve += oneknown;
		}
		if (pict-solved-tbsolve == 1) {
			tbsolve++;
		}
		cout << tbsolve << endl;
	}
}