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
	ll t;
	cin >> t;
	bool oddeven = true;
	int turn = 1;
	FenwickTree ft(t+2);
	unordered_map<int, int> saver; 
	for (int i = 1; i <= t; i++) {
		int x;
		cin >> x;
		saver[x] = i;
		ft.update(i, 1);
	}
	int p = 1;
	int counter = 0;
	while (counter < t) {
		int curr;
		if (oddeven) {
			curr = saver[p];
			cout << ft.rsq(1, curr-1) << endl;
		}
		else {
			curr = saver[t-p+1];
			cout << ft.rsq(curr+1, t) << endl;
		}
		ft.update(curr, -1);
		if (!oddeven) {
			p++;
		}
		oddeven = !oddeven;
		counter++;
	}
}