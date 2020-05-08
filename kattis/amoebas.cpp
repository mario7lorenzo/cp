#include <bits/stdc++.h>
using namespace std;

#define white 1
#define black -1

int dfs_num[15000];
bool grids[110][110];
map<int, vector<int>> al;

void dfs(int x) {
	dfs_num[x] = black;
	for (int i = 1; i < al[x].size(); i++) {
		int vtx = al[x][i];
		if (dfs_num[vtx] == white) {
			dfs(vtx);
		}
	}
}

int connected() {
	map<int, vector<int>>::iterator itr;
	int cc = 0;
	for (itr = al.begin(); itr != al.end(); itr++) {
		int val = itr->first;
		if (dfs_num[val] == white) {
			cc++;
			dfs(val);
		}
	}
	return cc;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n+5; i++) {
		for (int j = 0; j < m+5; j++) {
			grids[i][j] = false;
		}
	}
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < m+1; j++) {
			char dot;
			cin >> dot;
			if (dot == '#') {
				grids[i][j] = true;
			}
		}
	}
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < m+1; j++) {
			if (grids[i][j]) {
				int ind = ((i-1)*m)+j;
				al[ind].push_back(-1);
				if (grids[i-1][j]) {
					al[ind].push_back(ind-m);
				}
				if (grids[i+1][j]) {
					al[ind].push_back(ind+m);
				}
				if (grids[i][j-1]) {
					al[ind].push_back(ind-1);
				}
				if (grids[i][j+1]) {
					al[ind].push_back(ind+1);
				}
				if (grids[i-1][j-1]) {
					al[ind].push_back(ind-m-1);
				}
				if (grids[i-1][j+1]) {
					al[ind].push_back(ind-m+1);
				}
				if (grids[i+1][j-1]) {
					al[ind].push_back(ind+m-1);
				}
				if (grids[i+1][j+1]) {
					al[ind].push_back(ind+m+1);
				}
			}
		}
	}
	for (int i = 0; i < (n*m)+10; i++) {
		dfs_num[i] = white;
	}
	int amoeba = connected();
	cout << amoeba << endl;
}