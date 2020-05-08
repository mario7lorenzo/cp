#include <bits/stdc++.h>
using namespace std;

bool dfs_num[1000005];
set<int> lst;
unordered_map<int, vector<int>> al;

void dfs(int x) {
	lst.insert(x);
	dfs_num[x] = false;
	// cout << "ini x" << x << endl;
	for (int i = 0; i < al[x].size(); i++) {
		int vtx = al[x][i];
		// cout << "ini vtx " << vtx <<endl;
		if (dfs_num[vtx]) {
			dfs(vtx);
		}
	}
}

int main() {
    int m, s;
    cin >> m >> s;
    for (int i = 1; i <= s; i++) {
    	dfs_num[i] = true;
    }
    vector<vector<int>> songs;
    for (int i = 0; i < m; i++) {
        vector<int> temp;
        for (int j = 0; j < s; j++) {
            int song;
            cin >> song;
            temp.push_back(song);
        }
        songs.push_back(temp);
    }
   	for (int i = 0;i < m; i++) {
   		for (int j = 1; j < s; j++) {
   			al[songs[i][j]].push_back(songs[i][j-1]);
   		}
   	}
   	dfs(songs[0][0]);
   	// cout << "tes" << endl;
   	bool isfirst = true;
   	cout << lst.size() << endl;
   	for (auto i : lst) {
   		if (isfirst) {
   			isfirst = false;
   			cout << i;
   		}
   		else {
   			cout << ' ' << i;
   		}
   	}
   	cout << endl;
}