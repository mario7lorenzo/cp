#include <bits/stdc++.h>
using namespace std;

#define white 10
#define black -10

float life[10100];
map<int, vector<pair<float, int>>> al;

void dijkstra(int x) {
	life[x] = 1.0;
	priority_queue<pair<float, int>, vector<pair<float, int>>> pq;
	pq.push(make_pair(life[x], x));
	while (!pq.empty()) {
		pair<float, int> temp = pq.top();
		pq.pop();
		float w = temp.first;
		int u = temp.second;
		if (w < life[u]) {
			continue;
		}
		for (int i = 1; i < al[u].size(); i++) {
			pair<float, int> tmp = al[u][i];
			float we = tmp.first;
			int v = tmp.second;
			if (life[v] < life[u]*we) {
				life[v] = life[u]*we;
				pq.push(make_pair(life[v], v));
			}
		}
	}
}

void reset() {
	for (int i = 0; i < 10010; i++) {
		life[i] = 1e-9;
	}
}

int main() {
	int n, m;
	while (cin >> n >> m, n != 0 && m != 0) {
		for (int i = 0; i < n; i++) {
			al[i].emplace_back(1e-9, -1);
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			float w;
			cin >> x >> y >> w;
			al[x].emplace_back(w, y);
			al[y].emplace_back(w, x);
		}
		reset();
		dijkstra(0);
		cout << fixed << setprecision(4) << life[n-1] << endl;
		al.clear();
	}
}