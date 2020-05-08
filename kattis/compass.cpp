#include <bits/stdc++.h>
using namespace std;

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	int opt1 = abs(n2-n1);
	int opt2 = abs(360-opt1);
	if (opt1 <= opt2) {
		int temp = n1-opt1;
		while (temp < 0) {
			temp += 360;
		}
		if ((n1 + opt1)%360 == n2) {
			cout << opt1 << endl;
		}
		else if (temp%360 == n2) {
			cout << -opt1 << endl;
		}
	}
	else if (opt1 > opt2) {
		int temp = n1-opt2;
		while (temp < 0) {
			temp += 360;
		}
		if ((n1 + opt2)%360 == n2) {
			cout << opt2 << endl;
		}
		else if (temp%360 == n2) {
			cout << -opt2 << endl;
		}
	}
}