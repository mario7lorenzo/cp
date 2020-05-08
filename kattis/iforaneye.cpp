#include <bits/stdc++.h>
using namespace std;

bool ind(string x, string y) {
	if (x.length() != y.length()) {
		return false;
	}
	else {
		for (int i = 0; i < x.length(); i++) {
			if (x[i]%32 != y[i]%32) {
				return false;
			}
		}
		return true;
	}
}

int main() {
	bool isfirst = true;
	int testcase;
	cin >> testcase;
	for (int k = 0; k < testcase; k++) {
		string p;
		if (isfirst) {
			cin.ignore();
			isfirst = false;
		}
		getline(cin, p);
		// cout<< p << endl;
		string final = "";
		int i = 0;
		while (i < p.length()) {
			bool done = false;
			// cout << "ini p[i] " << p[i] << endl;
			if (p[i] == 'a') {
				if (i+2 < p.length()) {
					if (ind(p.substr(i, 3),"and")) {
						final += '&';
						i += 3;
						done = true;
					}
					else if (ind(p.substr(i, 3), "are")) {
						final += 'r';
						i += 3;
						done = true;
					}
				}
				if (i+1 < p.length() && !done) {
					if (ind(p.substr(i, 2), "at")) {
						final += '@';
						i += 2;
						done = true;
					}
				}
			}
			else if (p[i] == 'A') {
				if (i+2 < p.length()) {
					if (ind(p.substr(i, 3), "And")) {
						final += '&';
						i += 3;
						done = true;
					}
					else if (ind(p.substr(i, 3), "Are")) {
						final += 'R';
						i += 3;
						done = true;
					}
				}
				if (i+1 < p.length() && !done) {
					if (ind(p.substr(i, 2), "At")) {
						final += '@';
						i += 2;
					}
				}
			}
			else if (p[i] == 'b') {
				if (i+2 < p.length()) {
					if (ind(p.substr(i, 3), "bee")) {
						final += 'b';
						i += 3;
						done = true;
					}
					else if (ind(p.substr(i, 3), "bea")) {
						final += 'b';
						i += 3;
						done = true;
					}
				}
				if (i+1 < p.length() && !done) {
					if (ind(p.substr(i, 2), "be")) {
						final += 'b';
						i += 2;
						done = true;
					}
				}
			}
			else if (p[i] == 'B') {
				if (i+2 < p.length()) {
					if (ind(p.substr(i, 3), "bee")) {
						final += 'B';
						i += 3;
						done = true;
					}
					else if (ind(p.substr(i, 3), "bea")) {
						final += 'B';
						i += 3;
						done = true;
					}
				}
				if (i+1 < p.length() && !done) {
					if (ind(p.substr(i, 2), "be")) {
						final += 'B';
						i += 2;
						done = true;
					}
				}
			}
			else if (p[i] == 'e') {
				if (i+2 < p.length()) {
					if (ind(p.substr(i, 3), "eye")) {
						final += 'i';
						i += 3;
						done = true;
					}
				}
			}
			else if (p[i] == 'E') {
				if (i+2 < p.length()) {
					if (ind(p.substr(i, 3), "Eye")) {
						final += 'I';
						i += 3;
						done = true;
					}
				}
			}
			else if (p[i] == 'f') {
				if (i+3 < p.length()) {
					if (ind(p.substr(i, 4), "four")) {
						final += '4';
						i += 4;
						done = true;
					}
				}
				if (i+2 < p.length()  && !done) {
					if (ind(p.substr(i, 3), "for")) {
						final += '4';
						i += 3;
						done = true;
					}
				}
			}
			else if (p[i] == 'F') {
				if (i+3 < p.length()) {
					if (ind(p.substr(i, 4), "Four")) {
						final += '4';
						i += 4;
						done = true;
					}
				}
				if (i+2 < p.length() && !done) {
					if (ind(p.substr(i, 3), "For")) {
						final += '4';
						i += 3;
						done = true;
					}
				}
			}
			else if (p[i] == 'o') {
				if (i+2 < p.length()) {
					if (ind(p.substr(i, 3), "one")) {
						final += '1';
						i += 3;
						done = true;
					}
					else if (ind(p.substr(i, 3), "owe")) {
						final += 'o';
						i += 3;
						done = true;
					}
				}
				if (i+1 < p.length() && !done) {
					if (ind(p.substr(i, 2), "oh")) {
						final += 'o';
						i += 2;
					}
				}
			}
			else if (p[i] == 'O') {
				if (i+2 < p.length()) {
					if (ind(p.substr(i, 3), "One")) {
						final += '1';
						i += 3;
						done = true;
					}
					else if (ind(p.substr(i, 3), "Owe")) {
						final += 'O';
						i += 3;
						done = true;
					}
				}
				if (i+1 < p.length() && !done) {
					if (ind(p.substr(i, 2), "Oh")) {
						final += 'O';
						i += 2;
					}
				}
			}
			else if (p[i] == 's') {
				if (i+2 < p.length()) {
					if (ind(p.substr(i, 3), "sea")) {
						final += 'c';
						i += 3;
						done = true;
					}
					else if (ind(p.substr(i, 3), "see")) {
						final += 'c';
						i += 3;
						done = true;
					}
				}
			}
			else if (p[i] == 'S') {
				if (i+2 < p.length()) {
					if (ind(p.substr(i, 3), "Sea")) {
						final += 'C';
						i += 3;
						done = true;
					}
					else if (ind(p.substr(i, 3), "See")) {
						final += 'c';
						i += 3;
						done = true;
					}
				}
			}
			else if (p[i] == 't') {
				if (i+2 < p.length()) {
					if (ind(p.substr(i, 3), "too")) {
						final += '2';
						i += 3;
						done = true;
					}
					else if (ind(p.substr(i, 3), "two")) {
						final += '2';
						i += 3;
						done = true;
					}
				}
				if (i+1 < p.length() && !done) {
					if (ind(p.substr(i, 2), "to")) {
						final += '2';
						i += 2;
						done = true;
					}
				}
			}
			else if (p[i] == 'T') {
				if (i+2 < p.length()) {
					if (ind(p.substr(i, 3), "too")) {
						final += '2';
						i += 3;
						done = true;
					}
					else if (ind(p.substr(i, 3), "two")) {
						final += '2';
						i += 3;
						done = true;
					}
				}
				if (i+1 < p.length() && !done) {
					if (ind(p.substr(i, 2), "to")) {
						final += '2';
						i += 2;
						done = true;
					}
				}
			}
			else if (p[i] == 'w') {
				if (i+2 < p.length()) {
					if (ind(p.substr(i, 3), "won")) {
						final += '1';
						i += 3;
						done = true;
					}
					else if (ind(p.substr(i, 3), "why")) {
						final += 'y';
						i += 3;
						done = true;
					}
				}
			}
			else if (p[i] == 'W') {
				if (i+2 < p.length()) {
					if (ind(p.substr(i, 3), "won")) {
						final += '1';
						i += 3;
						done = true;
					}
					else if (ind(p.substr(i, 3), "why")) {
						final += 'Y';
						i += 3;
						done = true;
					}
				}
			}
			else if (p[i] == 'y') {
				if (i+2 < p.length()) {
					if (ind(p.substr(i, 3), "you")) {
						final += 'u';
						i += 3;
						done = true;
					}
				}
			}
			else if (p[i] == 'Y') {
				if (i+2 < p.length()) {
					if (ind(p.substr(i, 3), "you")) {
						final += 'U';
						i += 3;
						done = true;
					}
				}
			}
			if (!done) {
				final += p[i];
				i++;
			}
			// cout << "ini final skr " << final << endl;
		}
		cout << final << endl;
	}
}