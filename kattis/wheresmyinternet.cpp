#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define white 1
#define black -1

int dfs_num[200500];
map<int, vector<int>> al;
unordered_set<int> saver;
queue<int> q;

void dfs(int x) {
	saver.insert(x);
	dfs_num[x-1] = black;
	for (int i = 0; i < al[x].size(); i++) {
		int vtx = al[x][i];
		if (dfs_num[vtx-1] == white) {
			dfs(vtx);
		}
	}
}

// 1. DFS Implementation

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		dfs_num[i] = white;
	}
	dfs(1);
	if (saver.size() == n) {
		cout << "Connected" << endl;
	}
	else {
		for (int i = 1; i < n+1; i++) {
			if (saver.find(i) == saver.end()) {
				cout << i << endl;
			}
		}
	}
}

// 2. BFS Implementation

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		dfs_num[i] = white;
	}
	q.push(1);
	saver.insert(1);
	while (!q.empty()) {
		for (int i = 0; i < al[q.front()].size(); i++) {
			if (dfs_num[al[q.front()][i]-1] == white) {
				saver.insert(al[q.front()][i]);
				q.push(al[q.front()][i]);
				dfs_num[al[q.front()][i]-1] = black;
			}
		}
		dfs_num[q.front()-1] = black;
		q.pop();
	}
	if (saver.size() == n) {
		cout << "Connected" << endl;
	}
	else {
		for (int i = 1; i < n+1; i++) {
			if (saver.find(i) == saver.end()) {
				cout << i << endl;
			}
		}
	}
}