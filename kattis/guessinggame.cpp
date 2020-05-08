#include <bits/stdc++.h>
using namespace std;

int main() {
	string val;
	int highlow = -1, lowhigh = 11;
	while (getline(cin, val), val != "0") {
		string stats;
		getline(cin, stats);
		if (stats == "too high") {
			lowhigh = min(stoi(val), lowhigh);
		}
		else if (stats == "too low") {
			highlow = max(stoi(val), highlow);
		}
		else if (stats == "right on") {
			// cout << lowhigh << ' ' << highlow << endl;
			if (stoi(val) < lowhigh && stoi(val) > highlow) {
				cout << "Stan may be honest" << endl;
			}
			else {
				cout << "Stan is dishonest" << endl;
			}
			highlow = -1;
			lowhigh = 11;
		}
	}
}