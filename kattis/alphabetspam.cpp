#include <bits/stdc++.h>
using namespace std;

int main() {
	string p;
	cin >> p;
	double upper = 0, lower = 0, white = 0, symbol = 0;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '_') {
			white++;
		}
		else if (65 <= int(p[i]) && int(p[i]) <= 90) {
			upper++;
		}
		else if (97 <= int(p[i]) && int(p[i]) <= 122) {
			lower++;
		}
		else {
			symbol++;
		}
	}
	upper /= p.length();
	lower /= p.length();
	white /= p.length();
	symbol /= p.length();
	cout << fixed << setprecision(12) << white << endl;
	cout << fixed << setprecision(12) << lower << endl;
	cout << fixed << setprecision(12) << upper << endl;
	cout << fixed << setprecision(12) << symbol << endl;
}