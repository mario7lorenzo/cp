#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	ll n, m;
	while (cin >> n >> m, !(n == 0 && m == 0)) {
		vector<vector<ll>> saver;
		for (int i = 0; i < n; i++) {
			vector<ll> temp;
			ll so, de, st, du;
			cin >> so >> de >> st >> du;
			temp.push_back(so);
			temp.push_back(de);
			temp.push_back(st);
			temp.push_back(du);
			saver.push_back(temp);
		}
		for (int i = 0; i < m; i++) {
			ll c, d, counter = 0;
			cin >> c >> d;
			d = d + c - 1;
			// cout << "otto " << c << ' ' << d << endl;
			for (auto i : saver) {
				ll start = i[2], finish = i[3]+i[2]-1;
				// cout << "sf " << start << ' ' << finish << endl;
				if ((start <= c && finish <= d && finish >= c) 
					|| (start >= c && start <= d && finish >= c && finish <= d) 
					|| (start >= c && start <= d && finish >= d) 
					|| (c >= start && d <= finish)) {
					// cout << "otto " << start << ' ' << finish << endl;
					counter++;
				}
			}
			cout << counter << endl;
		}
	}
}