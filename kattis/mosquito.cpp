#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, p, l, e, r, s, n;
	while (cin >> m >> p >> l >> e >> r >> s >> n) {
		for (int i = 0; i < n; i++) {
			int mtemp = p/s;
			int ptemp = l/r;
			int ltemp = m*e;
			m = mtemp;
			p = ptemp;
			l = ltemp;
		}
		cout << m << endl;
	}
}