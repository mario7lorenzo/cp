#include <bits/stdc++.h>
using namespace std;

#define white 10
#define odd 5
#define even 4

int dfs_num[500005];
bool bipartite = 1;
bool initial = true;
unordered_map<int, vector<int>> al;

void dfs(int x) {
	for (int i = 1; i < al[x].size(); i++) {
		if (dfs_num[al[x][i]] == -1) {
			dfs_num[al[x][i]] = 1 - dfs_num[x];
			dfs(al[x][i]);
		}
		else if (dfs_num[al[x][i]] == dfs_num[x]) {
			bipartite = 0;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		al[i].push_back(-1);
		dfs_num[i] = true;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		dfs_num[i] = -1;
	}
	int cc = 0;
	// cout << al.size() << endl;
	for (int i = 1; i <= n; i++) {
		if (dfs_num[i] == -1) {
			dfs_num[i] = 0;
			dfs(i);
			cc++;
		}
	}
	if (!bipartite) {
		cc--;
	}
	// cout << bipartite << endl;
	cout << cc << endl;
}