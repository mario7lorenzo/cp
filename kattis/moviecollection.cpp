#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define LSOne(S) (S&(-S))

class FenwickTree {
    private:
      vll ft;
      ll n;

    public:
      FenwickTree(ll _n) : n(_n) {
        ft.assign(n+1, 0);
      }
      FenwickTree(const vector<ll>& f) : n(f.size()-1) {
        ft.assign(n+1, 0);
        for(ll i = 1; i <= n; i++) {
          ft[i] += f[i];
          if(i+LSOne(i) <= n) {
            ft[i+LSOne(i)] += ft[i];
          }
        }
      }
      ll rsq(ll j) {
        ll sum = 0;
        for (; j; j-= LSOne(j)) {
          sum += ft[j];
        }
        return sum;
      }
      ll rsq(ll i, ll j) {
        return rsq(j) - rsq(i-1);
      }
      void update(ll i, ll v) {
        for (; i <= n; i += LSOne(i)) {
          ft[i] += v;
        }
      }
    };

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll m, r;
		cin >> m >> r;
		FenwickTree ft(m+r);
		long long turn = 1;
		unordered_map<int, int> saver;
		for (int i = 1; i <= m; i++) {
			ft.update(i, 1);
			saver[i] = m-i+1;
		}
		while (r--) {
			int x;
			cin >> x;
			int curr = saver[x];
			// cout << curr << endl;
			cout << ft.rsq(curr+1, turn+m) << ' ';
			ft.update(curr, -1);
			saver[x] = turn+m;
			ft.update(saver[x], 1);
			turn++;
		}
		cout << endl;
	}
}