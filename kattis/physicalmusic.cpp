#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		vector<int> ori;
		vector<int> kecil;
		int rank;
		cin >> rank;
		priority_queue<int> pq;
		for (int i = 1; i <= rank; i++) {
			int x;
			cin >> x;
			ori.push_back(x);
		}
		int mini = 1e9;
		kecil.push_back(mini);
		for (int i = rank-1; i > 0; i--) {
			mini = min(mini, ori[i]);
			kecil.push_back(mini);
		}
		reverse(kecil.begin(), kecil.end());
		for (int i = 0; i < rank; i++) {
			if (ori[i] > kecil[i]) {
				pq.push(-ori[i]);
			}
		}
		cout << pq.size() << endl;
		while (!pq.empty()) {
			cout << -pq.top() << endl;
			pq.pop();
		}
	}
}