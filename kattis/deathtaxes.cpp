#include <bits/stdc++.h>
using namespace std;

int main() {
	double avg = 0, tot = 0;
	int shares = 0, x, y;
	string p;
	while (cin >> p) {
		if (p == "buy") {
			cin >> x >> y;
			shares += x;
			tot += (double(x)*double(y));
			avg = tot/shares;
		}
		else if (p == "sell") {
			cin >> x >> y;
			shares -= x;
			tot -= (avg*double(x));
		}
		else if (p == "split") {
			cin >> x;
			shares *= x;
			avg /= double(x);
		}
		else if (p == "merge") {
			cin >> x;
			tot -= double((shares%x))*avg;
			avg *= double(x);
			shares /= x;
		}
		else {
			cin >> x;
			if (x <= avg) {
				cout << fixed << setprecision(10) << shares*(x) << endl;
			}
			else {
				double profit = double(x) - avg;
				// cout << "ini profit " << profit <<endl;
				cout << fixed << setprecision(10) << double(shares) * (double(x)-(0.3*profit)) << endl;
			}
		}
		// cout << "ini shares " << shares << endl;
		// cout << "ini avg " << avg << endl;
		// cout << "ini tot " << tot << endl;
	}
}