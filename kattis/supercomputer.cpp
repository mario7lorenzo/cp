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
	ll n, k;
	cin >> n >> k;
	FenwickTree ft(n);
	vector<bool> saver;
	saver.assign(n+1, false);
	char comm;
	while (k--) {
		cin >> comm;
		if (comm == 'F') {
			ll x;
			cin >> x;
			if (!saver[x]) {
				ft.update(x, 1);
			}
			else {
				ft.update(x, -1);
			}
			saver[x] = !saver[x];
		}
		else if (comm == 'C') {
			int x, y;
			cin >> x >> y;
			cout << ft.rsq(x, y) << endl;
		}
	}
}