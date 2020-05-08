#include <bits/stdc++.h>
using namespace std;

int main() {
	double r, m, c;
	while (cin >> r >> m >> c, r != 0 && m != 0 && c != 0) {
		double trueval = M_PI * pow(r, 2);
		double estval = (c/m)*4*pow(r, 2);
		cout << fixed << setprecision(7) << trueval << ' ' << estval << endl;
	}
}