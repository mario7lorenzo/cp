#include <bits/stdc++.h>
using namespace std;

int main() {
	string p;
	getline(cin, p);
	string final = "";
	for (int i = 0; i < p.length(); i++) {
		bool done = false;
		if (p[i] == 'a' || p[i] == 'A') {
			final += "@";
			done = true;
		}
		if (p[i] == 'b' || p[i] == 'B') {
			final += "8";
			done = true;
		}
		if (p[i] == 'c' || p[i] == 'C') {
			final += "(";
			done = true;
		}
		if (p[i] == 'd' || p[i] == 'D') {
			final += "|)";
			done = true;
		}
		if (p[i] == 'e' || p[i] == 'E') {
			final += "3";
			done = true;
		}
		if (p[i] == 'f' || p[i] == 'F') {
			final += "#";
			done = true;
		}
		if (p[i] == 'g' || p[i] == 'G') {
			final += "6";
			done = true;
		}
		if (p[i] == 'h' || p[i] == 'H') {
			final += "[-]";
			done = true;
		}
		if (p[i] == 'i' || p[i] == 'I') {
			final += "|";
			done = true;
		}
		if (p[i] == 'j' || p[i] == 'J') {
			final += "_|";
			done = true;
		}
		if (p[i] == 'k' || p[i] == 'K') {
			final += "|<";
			done = true;
		}
		if (p[i] == 'l' || p[i] == 'L') {
			final += "1";
			done = true;
		}
		if (p[i] == 'm' || p[i] == 'M') {
			final += "[]\\/[]";
			done = true;
		}
		if (p[i] == 'n' || p[i] == 'N') {
			final += "[]\\[]";
			done = true;
		}
		if (p[i] == 'o' || p[i] == 'O') {
			final += "0";
			done = true;
		}
		if (p[i] == 'p' || p[i] == 'P') {
			final += "|D";
			done = true;
		}
		if (p[i] == 'q' || p[i] == 'Q') {
			final += "(,)";
			done = true;
		}
		if (p[i] == 'r' || p[i] == 'R') {
			final += "|Z";
			done = true;
		}
		if (p[i] == 's' || p[i] == 'S') {
			final += "$";
			done = true;
		}
		if (p[i] == 't' || p[i] == 'T') {
			final += "']['";
			done = true;
		}
		if (p[i] == 'u' || p[i] == 'U') {
			final += "|_|";
			done = true;
		}
		if (p[i] == 'v' || p[i] == 'V') {
			final += "\\/";
			done = true;
		}
		if (p[i] == 'w' || p[i] == 'W') {
			final += "\\/\\/";
			done = true;
		}
		if (p[i] == 'x' || p[i] == 'X') {
			final += "}{";
			done = true;
		}
		if (p[i] == 'y' || p[i] == 'Y') {
			final += "`/";
			done = true;
		}
		if (p[i] == 'z' || p[i] == 'Z') {
			final += "2";
			done = true;
		}
		if (!done) {
			final += p[i];
		}
	}
	cout << final << endl;
}