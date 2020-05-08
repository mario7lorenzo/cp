#include <bits/stdc++.h>
using namespace std;

#define white 1
#define black -1

map<int, vector<int>> al;
int dfs_num[100000];

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
	int cc = 0;
	map<int, vector<int>>::iterator itr;
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
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int city, road;
		cin >> city >> road;
		// cout << "ini city " << city << endl;
		// cout << "ini road " << road << endl;
		for (int i = 0; i < city; i++) {
			al[i].push_back(-1);
		}
		for (int j = 0; j < road; j++) {
			int a, b;
			cin >> a >> b;
			al[a].push_back(b);
			al[b].push_back(a);
		}
		for (int i = 0; i < 100000; i++) {
			dfs_num[i] = white;
		}
		map<int, vector<int>>::iterator itr;
		// for (itr = al.begin(); itr != al.end(); itr++) {
		// 	int val = itr->first;
		// 	cout << "ini val " << val << endl;
		// 	vector<int> isi = itr->second;
		// 	for (int j = 0; j < isi.size(); j++) {
		// 		cout << "ini isi " << isi[j] << endl;
		// 	}
		// }
		int roader = connected();
		cout << roader-1 << endl;
		al.clear();
	}
}