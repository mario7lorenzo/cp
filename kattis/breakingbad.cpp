#include <bits/stdc++.h>
using namespace std;

#define white 1
#define black -1
#define gray 2
#define odd 4
#define even 5

map<int, vector<int>> al;
map<string, int> id;
int dfs_num[100100];
bool color = true;
bool bip = true;
map<int, string> id2;
unordered_set<string> odder;
unordered_set<string> evener;
bool initial;
map<int, int> parent;

void dfs(int x) {
	if (initial) {
		dfs_num[x] = odd;
		initial = false;
	}
	else if (dfs_num[parent[x]] == odd) {
		dfs_num[x] = even;
	}
	else if (dfs_num[parent[x]] == even) {
		dfs_num[x] = odd;
	}
	for (int i = 1; i < al[x].size(); i++) {
		int vtx = al[x][i];
		if (dfs_num[vtx] == white) {
			parent[vtx] = x;
			dfs(vtx);
		}
		else if (dfs_num[x] == dfs_num[vtx]) {
			bip = false;
		}
	}
}

void bipartitechecker() {
	map<int, vector<int>>::iterator itr;
	for (itr = al.begin(); itr != al.end(); itr++) {
		int node = itr->first;
		if (dfs_num[node] == white) {
			initial = true;
			dfs(node);
		}
	}
}

int main() {
	int n;
	cin >> n;
	int idcounter = 0;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		id[temp] = idcounter;
		id2[idcounter] = temp;
		dfs_num[id[temp]] = white;
		al[id[temp]].push_back(-1);
		idcounter++;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		al[id[a]].push_back(id[b]);
		al[id[b]].push_back(id[a]);
	}
	bipartitechecker();
	if (!bip) {
		cout << "impossible" << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (dfs_num[i] == odd) {
				odder.insert(id2[i]);
			}
			else if (dfs_num[i] == even) {
				evener.insert(id2[i]);
			}
		}
		bool isfirst = true;
		bool isfirst2 = true;
		unordered_set<string>::iterator itr;
		for (itr = odder.begin(); itr != odder.end(); itr++) {
			if (isfirst) {
				isfirst = false;
				cout << *itr;
			}
			else {
				cout << ' ' << *itr;
			}
		}
		cout << endl;
		for (itr = evener.begin(); itr != evener.end(); itr++) {
			if (isfirst2) {
				isfirst2 = false;
				cout << *itr;
			}
			else {
				cout << ' ' << *itr;
			}
		}
		cout << endl;
	}
}