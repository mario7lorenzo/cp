#include <bits/stdc++.h>
using namespace std;

int main() {
	double a, b, c;
	while (cin >> a >> b >> c, a != 0 && b != 0 && c != 0) {
		double maxi = -1;
		maxi = max(maxi, a);
		maxi = max(maxi, b);
		maxi = max(maxi, c);
		if (maxi == c) {
			if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
				cout << "right" << endl;
			}
			else {
				cout << "wrong" << endl;
			}
		}
		else if (maxi == b) {
			if (pow(a, 2) + pow(c, 2) == pow(b, 2)) {
				cout << "right" << endl;
			}
			else {
				cout << "wrong" << endl;
			}
		}
		else if (maxi == a) {
			if (pow(c, 2) + pow(b, 2) == pow(a, 2)) {
				cout << "right" << endl;
			}
			else {
				cout << "wrong" << endl;
			}
		}
	}
}