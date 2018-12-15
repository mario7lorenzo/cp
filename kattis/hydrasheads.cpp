#include <bits/stdc++.h>
using namespace std;

int h, t, moves;
void second() {
	t++;
	moves++;
}

void third() {
	h++;
	t -= 2;
	moves++;
}

void fourth() {
	h -= 2;
	moves++;
}

int main() {
	while (cin >> h >> t, h != 0 && t != 0) {
		moves = 0;
		if (t%2 == 1) {
			second();
		}
		if ((h%2 == 1 && (t/2)%2 == 0) || (h%2 == 0 && (t/2)%2 == 1)) {
			second();
			second();
		}
		while (t > 0) {
			third();
		}
		while (h > 0) {
			fourth();
		}
		cout << moves << endl;
		h = 1e9, t = 1e9;
	}
}