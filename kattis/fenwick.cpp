#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define LSOne(S) (S&(-S))
#define endl '\n'

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
        for(ll i = 0; i <= n; i++) {
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
    long long n, q;
    cin >> n >> q;
    FenwickTree ft(n+2);
    for (int i = 0; i < q; i++) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        char query;
        cin >> query;
        // cout << i << endl;
        if (query == '+') {
            long long a, b;
            cin >> a >> b;
            a++;
            // cout << b << endl;
            ft.update(a, b);
        }
        else if (query == '?') {
            long long a;
            cin >> a;
            a++;
            cout << ft.rsq(a-1) << endl;
        }       
    }
}