#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int sets, days;
		cin >> sets >> days;
		cout << sets << ' ' << (days*(days+3)/2) << endl;
	}
}