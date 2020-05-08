#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		double curr = 0;
		while (k--) {
			curr += 0.5;
			curr *= 2;
		}
		cout << int(curr) << endl;
	}
}