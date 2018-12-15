#include <bits/stdc++.h>
using namespace std;

int main() {
	double a, b, c, i, j, k;
	cin >> a >> b >> c >> i >> j >> k;
	double mini = min(min(a/i, b/j), c/k);
	cout << fixed << setprecision(10) << a-(mini*i) << ' ' << b-(mini*j) << ' ' << c-(mini*k) << endl;
}