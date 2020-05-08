#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 1; i < testcase+1; i++) {
		int n;
		cin >> n;
		vector<long long> x;
		vector<long long> y;
		for (int j = 0; j < n; j++) {
			long long temp;
			cin >> temp;
			x.push_back(temp);
		}
		for (int j = 0; j < n; j++) {
			long long temp;
			cin >> temp;
			y.push_back(temp);
		}
		sort(x.rbegin(), x.rend());
		sort(y.begin(), y.end());
		long long tot = 0;
		for (int j = 0; j < n; j++) {
			tot += (x[j]*y[j]);
		}
		cout << "Case #" << i << ": " << tot << endl;
	}
}