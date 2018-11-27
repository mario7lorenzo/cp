#include <bits/stdc++.h>
using namespace std;

#define inf 1e9

map<int, vector<pair<int, int>>> al;
int dist[10500];
int p[10500];

void dijkstra(int x) {
	p[x] = -1;
	dist[x] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(dist[x], x));
	while (!pq.empty()) {
		pair<int, int> temp = pq.top();
		pq.pop();
		int w = temp.first; int u = temp.second;
		if (w > dist[u]) {
			continue;
		}
		for (int i = 0; i < al[u].size(); i++) {
			pair<int, int> tmp = al[u][i];
			int weight = tmp.first;
			int vtx = tmp.second;
			if (dist[vtx] > dist[u]+weight) {
				dist[vtx] = dist[u]+weight;
				pq.push(make_pair(dist[vtx], vtx));
			}
		}
	}
}

void reset() {
	for (int i = 0; i < 10500; i++) {
		dist[i] = inf;
	}
}

int main() {
	int n, m, q, s;
	bool isfirst = true;
	while (cin >> n >> m >> q >> s) {
		if (n == 0 && m == 0 && q == 0 && s == 0) {
			break;
		}
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			al[u].emplace_back(w, v);
		}
		reset();
		if (isfirst) {
			isfirst = false;
		}
		else {
			cout << endl;
		}
		dijkstra(s);
		for (int i = 0; i < q; i++) {
			int node;
			cin >> node;
			if (dist[node] == inf) {
				cout << "Impossible" << endl;
			}
			else {
				cout << dist[node] << endl;
			}
		}
		al.clear();
	}
}