#include <bits/stdc++.h>
using namespace std;

bool pr[32001];

int main() {
	for (int i = 0; i <= 32000; i++) {
		pr[i] = true;
	}
	pr[0] = false;
	pr[1] = false;
	for (int i = 0; i <= 32000; i++) {
		if (pr[i]) {
			for (int j = 2*i; j <= 32000; j+=i) {
				pr[j] = false;
			}
		}
	}
	int t;
	cin >> t;
	bool isfirst = true;
	while(t--) {
		if (isfirst) {
			isfirst = false;
		}
		else {
			cout << endl;
		}
		int x;
		cin >> x;
		vector<pair<int, int>> lst;
		for (int i = 2; i <= x/2; i++) {
			if (pr[i]) {
				int temp = x-i;
				if (pr[temp]) {
					lst.emplace_back(i, temp);
				}
			}
		}
		cout << x << " has " << lst.size() << " representation(s)" << endl;
		for (int i = 0; i < lst.size(); i++) {
			cout << lst[i].first << '+' << lst[i].second << endl;
		}
	}
}