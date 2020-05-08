#include <bits/stdc++.h>
using namespace std;

long long inf = 1e18;
vector<vector<pair<int, long long>>> ori;
bool is_visited[50000];
long long dist[50000];
int v = -1;
int k = -1;

void dfs(int x, int turn) {
	if (turn > k || dist[x] == inf) {

	} else {
		int ori_val = x % v;
		for (pair<int, long long> neighbor : ori[ori_val]) {
			int n = neighbor.first + (turn * v);
			long w = neighbor.second;
			if (n < k * v) {
				if (dist[n] > dist[x] + w) {
					dist[n] = dist[x] + w;
				}

				dfs(n, turn + 1);
			}
			
		}
	}
}

void shortest_path_dag(int x) {
	dist[x] = 0;
	dfs(x, 1);
}

int main() {
	int tc;
	cin >> tc;
	bool is_first = true;
	while (tc--) {
		if (is_first) {
			is_first = false;
		} else {
			cout << endl;
		}

		cin >> v;
		for (int i = 0; i < v; i++) {
			vector<pair<int, long long>> temp;
			ori.push_back(temp);
			int e;
			cin >> e;
			for (int j = 0; j < e; j++) {
				int n;
				long long w;
				cin >> n >> w;
				ori[i].push_back(make_pair(n, w));
			}
		}

		int q;
		cin >> q;

		while (q--) {
			int s, t;
			cin >> s >> t >> k;

			int tot = v * k;
			for (int i = 0; i < tot; i++) {
				is_visited[i] = false;
				dist[i] = inf;
			}

			shortest_path_dag(s);
			long long mini = inf;
			for (int i = t; i < tot; i += v) {
				mini = min(mini, dist[i]);
			}

			if (mini == inf) {
				cout << -1 << endl;
			} else {
				cout << mini << endl;
			}
		}
		ori.clear();
	}

}