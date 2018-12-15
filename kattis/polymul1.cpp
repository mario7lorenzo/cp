#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int deg1, deg2;
		cin >> deg1;
		vector<long long> p1, p2, p;
		for (int i = 0; i <= deg1; i++) {
			long long x;
			cin >> x;
			p1.push_back(x);
		}
		cin >> deg2;
		for (int i = 0; i <= deg2; i++) {
			long long x;
			cin >> x;
			p2.push_back(x);
		}
		cout << deg1+deg2 << endl;
		for (int i = 0; i <= deg1+deg2; i++) {
			p.push_back(0);
		}
		for (int i = 0; i < p1.size(); i++) {
			for (int j = 0; j < p2.size(); j++) {
				p[i+j] += (p1[i] * p2[j]);
			}
		}
		for (int i = 0; i < p.size(); i++) {
			if (i == 0) {
				cout << p[0];
			}
			else {
				cout << ' ' << p[i];
			}
		}
		cout << endl;
	}
}