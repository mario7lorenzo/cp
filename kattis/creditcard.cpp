#include <bits/stdc++.h>
using namespace std;

long long rounder(double x) {
	return 100.0 * x + 0.5;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		double r, b, m;
		cin >> r >> b >> m;
		long long rl = rounder(r);
		long long bl = rounder(b);
		long long ml = rounder(m);
		int payment = 0;
		while (bl > 0) {
			long long interest = bl*rl;
			if (interest%10000 >= 5000) {
				interest /= 10000;
				interest++;
			}
			else {
				interest /= 10000;
			}
			bl += interest;
			bl -= ml;
			payment++;
			if (payment > 1200) {
				break;
			}
			// cout << "ini payment " << payment << endl;
			// cout << "ini b " << b << endl;
		} 
		if (payment > 1200) {
			cout << "impossible" << endl;
		}
		else {
			cout << payment << endl;
		}
	}
}