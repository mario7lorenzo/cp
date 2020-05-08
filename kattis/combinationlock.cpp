#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		if ((a == 0 && b == 0 && c == 0 && d == 0)) {
			break;
		}
		int deg = 120;
		deg += (((a-b)+40)%40);
		deg += (((c-b)+40)%40);
		deg += (((c-d)+40)%40);
		cout << deg*9 << endl;
	}
}