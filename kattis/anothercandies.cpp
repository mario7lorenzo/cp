#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		long long total;
		cin >> total;
		long long mod = 0;
		for (long long j = 0; j < total; j++) {
			long long x;
			cin >> x;
			mod += x % total;
			mod %= total;
		}
		if (mod != 0) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}	
}