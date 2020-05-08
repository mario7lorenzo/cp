#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> seq;
	unordered_map<int, int> freq;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		seq.push_back(x);
		freq[x]++;
	}
	priority_queue<int> pq;
	int maxi = -1;
	for (int i = 1; i <= n+1; i++) {
		if (freq.find(i) == freq.end()) {
			pq.push(-i);
			maxi = i;
		}
	}
	bool can = true;
	vector<int> final;
	if (maxi == n+1 || pq.size() == 0) {
		can = false;
	}
	else {
		for (auto i : seq) {
			// cout << i << endl;
			if (pq.empty()) {
				can = false;
				break;
			}
			int temp = -pq.top();
			// cout << "ini temp " << temp << endl;
			pq.pop();
			freq[i]--;
			final.push_back(temp);
			if (freq[i] == 0) {
				pq.push(-i);
			}
		}
	}
	// cout << can << endl;
	if (pq.size() > 1 || (pq.size() == 1 && pq.top() != -n-1)) {
		can = false;
	}
	if (can) {
		for (auto i : final) {
			cout << i << endl;
		}
	}
	else {
		cout << "Error" << endl;
	}
}