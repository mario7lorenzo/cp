#include <bits/stdc++.h>
using namespace std;

#define white true
#define black false

bool dfs_num[10050];
map<int, vector<int>> al;
bool star[100+2][100+2];

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
	int n, m;
	int counter = 0;
	while (scanf("%d %d", &n, &m) != EOF) {
		counter++;
		for (int i = 0; i < n+2; i++) {
			for (int j = 0; j < m+2; j++) {
				star[i][j] = false;
			}
		}
		for (int i = 1; i < n+1; i++) {
			for (int j = 1; j < m+1; j++) {
				char sym;
				cin >> sym;
				if (sym == '-') {
					star[i][j] = true;
				}
			}
		}
		for (int i = 1; i < n+1; i++) {
			for (int j = 1; j < m+1; j++) {
				if (star[i][j] == true) {
					int ind = ((i-1)*m) + j;
					al[ind].push_back(0);
					if (star[i][j-1] == true) {
                        al[ind].push_back(ind-1);
                    }
                    if (star[i][j+1] == true) {
                        al[ind].push_back(ind+1);
                    }
                    if (star[i-1][j] == true) {
                        al[ind].push_back(ind-m);
                    }
                    if (star[i+1][j] == true) {
                        al[ind].push_back(ind+m);
                    }
				}
			}
		}
		for (int i = 0; i < 10050; i++) {
			dfs_num[i] = white;
		}
		map<int, vector<int>>::iterator itr;
		int res = connected();
		cout << "Case " << counter << ": "<< res << endl;
		al.clear();
	}
}