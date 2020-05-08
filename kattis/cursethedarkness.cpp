#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		double xb, yb;
		cin >> xb >> yb;
		int candles;
		cin >> candles;
		bool available = false;
		while (candles--) {
			double xc, yc, dist;
			cin >> xc >> yc;
			dist = ((xc-xb)*(xc-xb)) + ((yc-yb)*(yc-yb));
			if (dist <= 64) {
				available = true;
			}
		}
		if (available) {
			cout << "light a candle" << endl;
		}
		else {
			cout << "curse the darkness" << endl;
		}
	}
}