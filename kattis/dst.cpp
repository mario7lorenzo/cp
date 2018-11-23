#include <bits/stdc++.h>
using namespace std;

int main() {
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		char x;
		int d, y, z;
		cin >> x >> d >> y >> z;
		int time = (y * 60) + z;
		if (x == 'F') {
			time += d;
		}
		else {
			time -= d;
		}
		y = time / 60;
		z = time % 60;
		if (z >= 60) {
			z-= 60;
			y++;
		}
		if (z < 0) {
			z += 60;
			y--;
		}
		if (y < 0) {
			y += 24;
		}
		if (y >= 24) {
			y -= 24;
		}
		cout << y << " " << z << endl;
	}
}