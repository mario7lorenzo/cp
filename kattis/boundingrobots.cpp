#include <bits/stdc++.h>
using namespace std;

int main() {
	int w, l;
	while (cin >> w >> l, w != 0 && l != 0) {
		int op, xact = 0, yact = 0, xrob = 0, yrob = 0;
		cin >> op;
		for (int i = 0; i < op; i++) {
			char dir;
			int much;
			cin >> dir >> much;
			if (dir == 'l') {
				xact -= much;
				xrob -= much;
				if (xact < 0) {
					xact = 0;
				}
			}
			else if (dir == 'r') {
				xact += much;
				xrob += much;
				if (xact > w-1) {
					xact = w-1;
				}
			}
			else if (dir == 'u') {
				yact += much;
				yrob += much;
				if (yact > l-1) {
					yact = l-1;
				}
			}
			else if (dir == 'd') {
				yact -= much;
				yrob -= much;
				if (yact < 0) {
					yact = 0;
				}
			}
		}
		cout << "Robot thinks " << xrob << ' ' << yrob << endl;
		cout << "Actually at " << xact << ' ' << yact << endl;
		cout << endl;
	}
}