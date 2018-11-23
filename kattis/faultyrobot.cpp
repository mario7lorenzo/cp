#include <bits/stdc++.h>
using namespace std;

#define white 1
#define black -1
#define red 2
#define gray 3

pair<bool, vector<int>> ori;
pair<bool, vector<int>> art;
set<int> saver;
map<int, vector<pair<int, int>>> al;
int dfs_num[1050];

void reset(int n) {
	for (int i = 0; i < n+20; i++) {
		dfs_num[i] = white;
	}
}

void traverser(int nodes) {
	ori.second.push_back(nodes);
	dfs_num[nodes] = gray;
	for (int i = 1; i < al[nodes].size(); i++) {
		pair<int, int> temp = al[nodes][i];
		if (temp.second == red) {
			if (dfs_num[temp.first] == white) {
				traverser(temp.first);
			}
			else if (dfs_num[temp.first] == gray) {
				ori.first = true;
			}
		}
	}
	dfs_num[nodes] = black;
}

void traverser2(int nodes) {
	art.second.push_back(nodes);
	dfs_num[nodes] = gray;
	for (int i = 1; i < al[nodes].size(); i++) {
		pair<int, int> temp = al[nodes][i];
		if (temp.second == red) {
			if (dfs_num[temp.first] == white) {
				traverser2(temp.first);
			}
			else if (dfs_num[temp.first] == gray) {
				art.first = true;
			}
		}
	}
	dfs_num[nodes] = black;
}

void bugg(int x, int n) {
	for (int i = 1; i < al[x].size(); i++) {
		art.first = false;
		pair<int, int> temp = al[x][i];
 		if (temp.second == black) {
			traverser2(temp.first);
			if (!art.first) {
				saver.insert(art.second[art.second.size()-1]);
			}
		}
		reset(n);
		art.second.clear();
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n+1; i++) {
		al[i].emplace_back(0, black);
	}
	for (int i = 0; i < m; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		if (node1 < 0) {
			al[-node1].emplace_back(node2, red);
		}
		else {
			al[node1].emplace_back(node2, black);
		}
	}
	ori.first = false;
	reset(n);
	traverser(1);
	if (ori.first == false) {
		saver.insert(ori.second[ori.second.size()-1]);
	}
	reset(n);
	for (int i = 0; i < ori.second.size(); i++) {
		bugg(ori.second[i], n);
	}
	cout << saver.size() << endl;
}