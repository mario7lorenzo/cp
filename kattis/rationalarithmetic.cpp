#include <bits/stdc++.h>
using namespace std;

int main() {
	long long testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		long long na, da, nb, db, numer, denom;
		char op;
		cin >> na >> da >> op >> nb >> db;
		if (op == '+') {
			numer = (na*db) + (nb*da);
			denom = (da*db);
		}
		else if (op == '-') {
			numer = (na*db) - (nb*da);
			denom = (da*db);
		}
		else if (op == '*') {
			numer = (na*nb);
			denom = (da*db);
		}
		else if (op == '/') {
			numer = (na*db);
			denom = (da*nb);
		}
		if (denom < 0) {
			numer = -numer;
			denom = -denom;
		}
		long long fpb = __gcd(abs(numer), abs(denom));
		numer /= fpb;
		denom /= fpb;
		cout << numer << " / " << denom << endl;
	}
}