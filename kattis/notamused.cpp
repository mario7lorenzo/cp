#include <bits/stdc++.h>
using namespace std;

int main() {
	string p;
	int days = 0;
	map<string, double> lst;
	map<string, double> durr;
	bool isfirst = true;
	while (cin >> p) {
		if (p == "OPEN") {
			days++;
		}
		else if (p == "ENTER") {
			string name;
			double in;
			cin >> name >> in;
			lst[name] = in;
		}
		else if (p == "EXIT") {
			string name;
			double out;
			cin >> name >> out;
			lst[name] = out - lst[name];
			durr[name] += lst[name];
		}
		else if (p == "CLOSE") {
			if (isfirst) {
				isfirst = false;
			}
			else {
				cout << endl;
			}
			cout << "Day " << days << endl;
			map<string, double>::iterator it;
			for (it = durr.begin(); it != durr.end(); it++) {
				it->second *= 0.1;
				cout << fixed << setprecision(2) << it->first << " $" << it->second << endl;
			}
			lst.clear();
			durr.clear();
		}
	}
}