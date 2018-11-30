#include <bits/stdc++.h>
using namespace std;

#define white 10
#define black -10

int dfs_num[10100];
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

int main() {
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        int n, m, l;
        cin >> n >> m >> l;
        for (int j = 1; j < n+1; j++) {
            dfs_num[j] = white;
        }
        for (int j = 1; j < n+1; j++) {
            al[j].push_back(-1);
        }
        for (int j = 0; j < m; j++) {
            int x, y;
            cin >> x >> y;
            al[x].push_back(y);
        }
        for (int j = 0; j < l; j++) {
            int z;
            cin >> z;
            if (dfs_num[z] == white) {
                dfs(z);
            }
        }
        int counter = 0;
        for (int j = 1; j < n+1; j++) {
            if (dfs_num[j] == black) {
                counter++;
            }
        }
        cout << counter << endl;
    al.clear();
    }
}