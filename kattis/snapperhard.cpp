#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	int cases = 1;
	while (t--) {
		int n, snap;
		cin >> n >> snap;
		long long one = pow(2, n)-1;
		long long mods = snap%(one+1);
		if (mods == one) {
			cout << "Case #" << cases << ": ON" << endl;
		}
		else {
			cout << "Case #" << cases << ": OFF" << endl;
		}
		cases++;
	}
}