#include <bits/stdc++.h>
using namespace std;

int h, m;

void adjust() {
	if (m < 0) {
		h--;
		m += 60;
	}
	if (m >= 60) {
		m -= 60;
		h++;
	}
	if (h < 0) {
		h += 24;
	}
	if (h >= 24) {
		h -= 24;
	}
}

int main() {
	unordered_map<string, pair<int, int>> utc;
	utc["UTC"] = make_pair(0, 0);
	utc["GMT"] = make_pair(0, 0);
	utc["BST"] = make_pair(-1, 0);
	utc["IST"] = make_pair(-1, 0);
	utc["WET"] = make_pair(0, 0);
	utc["WEST"] = make_pair(-1, 0);
	utc["CET"] = make_pair(-1, 0);
	utc["CEST"] = make_pair(-2, 0);
	utc["EET"] = make_pair(-2, 0);
	utc["EEST"] = make_pair(-3, 0);
	utc["MSK"] = make_pair(-3, 0);
	utc["MSD"] = make_pair(-4, 0);
	utc["AST"] = make_pair(4, 0);
	utc["ADT"] = make_pair(3, 0);
	utc["NST"] = make_pair(3, 30);
	utc["NDT"] = make_pair(2, 30);
	utc["EST"] = make_pair(5, 0);
	utc["EDT"] = make_pair(4, 0);
	utc["CST"] = make_pair(6, 0);
	utc["CDT"] = make_pair(5, 0);
	utc["MST"] = make_pair(7, 0);
	utc["MDT"] = make_pair(6, 0);
	utc["PST"] = make_pair(8, 0);
	utc["PDT"] = make_pair(7, 0);
	utc["HST"] = make_pair(10, 0);
	utc["AKST"] = make_pair(9, 0);
	utc["AKDT"] = make_pair(8, 0);
	utc["AEST"] = make_pair(-10, 0);
	utc["AEDT"] = make_pair(-11, 0);
	utc["ACST"] = make_pair(-9, -30);
	utc["ACDT"] = make_pair(-10, -30);
	utc["AWST"] = make_pair(-8, 0);
	int tc;
	cin >> tc;
	while (tc--) {
		bool ampm = true;
		string tm;
		cin >> tm;
		string tz1, tz2;
		if (tm == "noon") {
			h = 12, m = 0;
			ampm = false;
			cin >> tz1 >> tz2;
		}
		else if (tm == "midnight") {
			h = 0, m = 0;
			cin >> tz1 >> tz2;
		}
		else {
			string daynight;
			cin >> daynight;
			if (daynight == "p.m.") {
				ampm = false;
			}
			string hsaver = "", msaver = "";
			bool hm = true;
			for (auto i : tm) {
				if (i == ':') {
					h = stoi(hsaver);
					hm = false;
				}
				else {
					if (hm) {
						hsaver += i;
					}
					else {
						msaver += i;
					}
				}
			}
			m = stoi(msaver);
			cin >> tz1 >> tz2;
 		}
 		if (ampm && h == 12) {
 			h = 0;
 		}
 		else if (!ampm && h < 12) {
 			h += 12;
 		}
 		h += utc[tz1].first;
 		m += utc[tz1].second;
 		adjust();
 		// cout << tz1 << endl;
 		h -= utc[tz2].first;
 		m -= utc[tz2].second;
 		adjust();
 		// cout << h << ' ' << m << endl;
 		if (h < 12) {
 			ampm = true;
 			if (h == 0) {
 				h += 12;
 			}
 		}
 		else {
 			ampm = false;
 			if (h != 12) {
 				h -= 12;
 			}
 		}
 		if (h == 12 && m == 0) {
 			if (ampm) {
 				cout << "midnight" << endl;
 			}
 			else {
 				cout << "noon" << endl;
 			}
 		}
 		else {
 			cout << h << ':';
 			if (m < 10) {
 				cout << 0 << m << ' ';
 			}
 			else {
 				cout << m << ' ';
 			}
 			if (ampm) {
 				cout << "a.m." << endl;
 			}
 			else {
 				cout << "p.m." << endl;
 			}
 		}
	}
}