#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		ll p,r,f;
		cin >> p >> r >> f;
		ll result = 0;
		while (p <= f) {
			result++;
			p *= r;
		}

		cout << result << endl;
	}
}