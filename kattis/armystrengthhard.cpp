#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		long long mech, god;
		cin >> god >> mech;
		long long maxgod = -999;
		long long maxmech = -999;
		for (long long j = 0; j < god; j++) {
			long long x;
			cin >> x;
			maxgod = max(maxgod, x);
		}
		for (long long j = 0; j < mech; j++) {
			long long x;
			cin >> x;
			maxmech = max(maxmech, x);
		}
		if (maxmech <= maxgod) {
			cout << "Godzilla" << endl;
		}
		else {
			cout << "MechaGodzilla" << endl;
		}
	}
}