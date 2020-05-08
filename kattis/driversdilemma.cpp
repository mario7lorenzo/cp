#include <bits/stdc++.h>
using namespace std;

int main() {
	double c, x, m;
	cin >> c >> x >> m;
	double init = c/2;
	int maxi = 0;
	for (int i = 0; i < 6; i++) {
		int speed;
		double eff;
		cin >> speed >> eff;
		double durr = m/double(speed);
		double used = (m/eff) + (durr*x);
		if (init-used >= 1e-6) {
			maxi = speed;
		}
	}
	if (!maxi) {
		cout << "NO" << endl;
	} else {
		cout << "YES " << maxi << endl; 
	}
}