#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	if ((x != 0 && y == 1)) {
		cout << "IMPOSSIBLE" << endl;
	}
	else if (x == 0 && y == 1) {
		cout << "ALL GOOD" << endl;
	}
	else {
		cout << fixed << setprecision(10) << double(x)/(1.0-(double(y))) << endl;
	}
}