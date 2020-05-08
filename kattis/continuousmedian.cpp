#include <bits/stdc++.h>
using namespace std;

#define pb push_back

priority_queue<int> small;
priority_queue<int, vector<int>, greater<int>> big;

void adjust() {
	if (small.size() - big.size() == 2) {
		int tops = small.top();
		small.pop();
		big.push(tops);
	} else if (big.size() - small.size() == 1) {
		int tops = big.top();
		big.pop();
		small.push(tops);
	}
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		vector<int> vi;
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			vi.pb(x);
		}
		
		long long sum = 0;
		
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				small.push(vi[i-1]);
				sum += vi[i-1];
			} else if (i == 2) {
				if (vi[i-2] <= vi[i-1]) {
					big.push(vi[i-1]);
				} else {
					small.pop();
					big.push(vi[i-2]);
					small.push(vi[i-1]);
				}
				sum += (vi[i-2] + vi[i-1]) / 2;
			} else {
				int left_biggest = small.top();
				int right_smallest = big.top();
				if (vi[i-1] <= left_biggest) {
					small.push(vi[i-1]);
				} else {
					big.push(vi[i-1]);
				}
				adjust();
				if (i%2) {
					sum += small.top();
				} else {
					sum += (small.top() + big.top()) / 2;
				}
			}
		}
		cout << sum << endl;
		small = priority_queue<int>();
		big = priority_queue<int, vector<int>, greater<int>>();
	}
}