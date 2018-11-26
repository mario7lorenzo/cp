#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d;
	int cases = 1;
	while (cin >> a >> b >> c >> d) {
		int det = (a*d)-(b*c);
		int af = d/det, bf = -b/det, cf = -c/det, df = a/det;
		cout << "Case " << cases << ":" << endl;
		cout << af << ' ' << bf << endl;
		cout << cf << ' ' << df << endl;
		cases++;
	}
}