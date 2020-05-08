#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<string, long long> saver;
	unordered_map<string, string> dir;
	saver["th"] = 1;
	saver["in"] = 1000;
	saver["ft"] = 12000;
	saver["yd"] = 36000;
	saver["ch"] = 792000;
	saver["fur"] = 7920000;
	saver["mi"] = 63360000;
	saver["lea"] = 190080000;
	dir["thou"] = "th";
	dir["inch"] = "in";
	dir["foot"] = "ft";
	dir["yard"] = "yd";
	dir["chain"] = "ch";
	dir["furlong"] = "fur";
	dir["mile"] = "mi";
	dir["league"] = "lea";
	double m;
	string init, dumin, fin;
	cin >> m >> init >> dumin >> fin;
	if (init.length() > 3) {
		init = dir[init];
	}
	if (fin.length() > 3) {
		fin = dir[fin];
	}
	cout << fixed << setprecision(15) << (m*saver[init])/saver[fin] << endl;
}