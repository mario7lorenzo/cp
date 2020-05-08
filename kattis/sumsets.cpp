#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll> lst;
	for (int i = 0; i < n; i++) {
		ll c;
		cin >> c;
		lst.push_back(c);
	}
	bool found = false;
	ll res;
	sort(lst.begin(), lst.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		int currtot = lst[i];
		for (int j = i+1; j < n; j++) {
			int tmp1 = currtot - lst[j];
			for (int k = j+1; k < n; k++) {
				int tmp2 = tmp1 - lst[k];
				for (int l = k+1; l < n; l++) {
					// cout << lst[i] << ' ' << lst[j] << ' ' << lst[k] << ' ' << lst[l] << ' ' << currtot << endl;
					if (lst[l] == tmp2) {
						res = lst[i];
						found = true;
						break;
					}
				}
				if (found) break;
			}
			if (found) break;
		}
		if (found) break;
	}
	if (!found) {
		cout << "no solution" << endl;
	}
	else {
		cout << res << endl;
	}
}
