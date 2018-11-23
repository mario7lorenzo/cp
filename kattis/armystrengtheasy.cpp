#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int mech, god;
		cin >> god >> mech;
		int maxgod = -999;
		int maxmech = -999;
		for (int j = 0; j < god; j++) {
			int x;
			cin >> x;
			maxgod = max(maxgod, x);
		}
		for (int j = 0; j < mech; j++) {
			int x;
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