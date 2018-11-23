#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d;
	int final = 0;
	int counter = 1;
	int cntr = 1;
	while (cin >> a >> b >> c >> d) {
		int summary = a + b + c + d;
		if (final < summary) {
			counter = cntr;
		}
		final = max(final, summary);
		cntr += 1;
	}
	cout << counter << ' ' << final << endl;
}