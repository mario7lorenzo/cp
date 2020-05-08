#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;

	vector<long long> vi;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vi.push_back(x);
	}

	sort(vi.begin(), vi.end());
	
	if (t == 1) {
		unordered_set<long long> uset;
		for (long long ll : vi) {
			uset.insert(7777 - ll);
		}
		bool exists = false;
		for (long long ll : vi) {
			if (uset.find(ll) != uset.end()) {
				exists = true;
				break;
			}
		}

		if (exists) {
			cout << "Yes" << endl; 
		} else {
			cout << "No" << endl;
		}
	} else if (t == 2) {
		unordered_set<long long> uset;
		for (long long ll : vi) {
			uset.insert(ll);
		}

		if (vi.size() == uset.size()) {
			cout << "Unique" << endl;
		} else {
			cout << "Contains duplicate" << endl;
		}
	} else if (t == 3) {
		unordered_map<long long, int> umap;
		bool contains = false;
		for (long long ll : vi) {
			umap[ll]++;
		}
		long long num = -1;
		unordered_map<long long, int>:: iterator it = umap.begin();
		for (it = umap.begin(); it != umap.end(); it++) {
			if (it->second > n / 2) {
				contains = true;
				num = it->first;
				break;
			}
		}
		cout << num << endl;
	} else if (t == 4) {
		sort(vi.begin(), vi.end());
		if (n%2) {
			cout << vi[(n - 1)/2] << endl;
		} else {
			cout << vi[(n/2) - 1] << ' ' << vi[n/2] << endl;
		}
	} else if (t == 5) {
		sort(vi.begin(), vi.end());
		bool is_first = true;
		for (long long ll : vi) {
			if (ll >= 100 && ll <= 999) {
				if (is_first) {
					cout << ll;
				} else {
					cout << ' ' << ll;
				}
				is_first = false;
			}
		}
		cout << endl;
	}
}
