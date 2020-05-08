#include <bits/stdc++.h>
using namespace std;

int main() {
	int inm = 4;
	int iny = 2018;
	int y;
	cin >> y;
	int curr = 2018;
	while (curr < y) {
		inm += 2;
		curr += 2;
		if (inm > 12) {
			inm -= 12;
			curr++;
		}
	}
	if (curr == y) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}