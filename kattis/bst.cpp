#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<long long, long long> saver;
	long long counter = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i == 0) {
			saver[x] = 0;
		}
		else {
			auto lowbond = saver.lower_bound(x);
			long long depthprev, depthaft;
			if (lowbond == saver.end()) {
				depthaft = 0;
			}
			else {
				depthaft = lowbond->second;
			}
			if (lowbond == saver.begin()) {
				depthprev = 0;
			}
			else {
				lowbond--;
				depthprev = lowbond->second;
			}
			long long depth = max(depthprev, depthaft)+1;
			saver[x] = depth;
			counter += depth;
		}
		cout << counter << endl;
	}
}