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
	ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
	int team, q;
  cin >> team >> q;
	FenwickTree ft(team);
	ft.update(team, 1);
	vector<pair<int, int>> scoresaver;
	for (int i = 0; i < team; i++) {
		scoresaver.emplace_back(0, 0);
	}
  bool above[100010];
  for (int i = 0; i < 100010; i++) {
    above[i] = false;
  }
	priority_queue<pair<int, pair<int, int>>> pq;
	while (q--) {
		int num, pen;
		cin >> num >> pen;
		scoresaver[num-1] = make_pair(scoresaver[num-1].first+1, scoresaver[num-1].second+pen);
		if (num != 1) {
			if (((scoresaver[num-1].first > scoresaver[0].first) || ((scoresaver[num-1].first == scoresaver[0].first) && (scoresaver[num-1].second < scoresaver[0].second)))) {
        if (above[num] == false) { 
          ft.update(team+1-num, 1);
          above[num] = true;
        }
        pq.push(make_pair(-scoresaver[num-1].first, make_pair(scoresaver[num-1].second, num)));
      }
		}
		else {
      while (!pq.empty()) {
        pair<int, pair<int, int>> temp = pq.top();
        int id = temp.second.second;
        if (above[id]) {
          if (-(temp.first) == scoresaver[id-1].first && temp.second.first == scoresaver[id-1].second) {
            int favscore = scoresaver[0].first, favpen = scoresaver[0].second;
            if (favscore > -temp.first || (favscore == -temp.first && favpen <= temp.second.first)) {
              ft.update(team+1-id, -1);
              above[id] = false;
              pq.pop();
            }
            else {
              break;
            }         
          }
          else {
            pq.pop();
          }
        }
        else {
          pq.pop();
        }
      }
		}
    cout << ft.rsq(team) << endl;
	}
}