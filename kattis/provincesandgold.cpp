#include <bits/stdc++.h>
using namespace std;

int main() {
	int g, s, c;
	cin >> g >> s >> c;
	int total = (g*3) + (s*2) + c;
	bool victory = false;
	if (total >= 8) {
		cout << "Province ";
		victory = true;
	}
	else if (total >= 5) {
		cout << "Duchy ";
		victory = true;
	}
	else if (total >= 2) {
		cout << "Estate ";
		victory = true;
	}
	if (victory) {
		cout << "or ";
	}
	if (total >= 6) {
		cout << "Gold" << endl;
	}
	else if (total >= 3) {
		cout << "Silver" << endl;
	}
	else {
		cout << "Copper" << endl;
	}
}