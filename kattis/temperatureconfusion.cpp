#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
	if (x == 0) {
		return y;
	}
	else if (y == 0) {
		return x;
	}
	else {
		int final = -1;
		for (int i = 1; i < min(x, y)+1; i++) {
			if (x%i == 0 && y%i == 0) {
				final = i;
			}
		}
		return final;
	}
}

int main() {
	string f;
	cin >> f;
	int numer, denom;
	string temp = "";
	for (int i = 0; i < f.length(); i++) {
		if (f[i] == '/') {
			numer = stoi(temp);
			temp = "";
		}
		else {
			temp += f[i];
		}
	}
	denom = stoi(temp);
	numer -= (32*denom);
	numer *= 5;
	denom *= 9;
	int fpb = gcd(abs(numer), abs(denom));
	numer /= fpb;
	denom /= fpb;
	cout << numer << '/' << denom << endl;
}