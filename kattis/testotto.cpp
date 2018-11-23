#include <bits/stdc++.h>
using namespace std;

#define white -2
#define black 1
#define biner 4
#define desimal 7

int mapp[1020][1020];
int bfs_num[1020][1020];

void bfs(int p, int l, int marker) {
    queue<pair<int, int>> q;
    q.push(make_pair(p, l));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        bfs_num[x][y] = marker;
        if (mapp[])
    }
}

int main() {
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r+2; i++) {
        for (int j = 0; j < c+2; j++) {
            mapp[i][j] = -1;
        }
    }
    for (int i = 1; i < r+1; i++) {
        string seq;
        cin >> seq;
        for (int j = 1; j < c+1; j++) {
            if (seq[j-1]=='1') {
                mapp[i][j] = 1;
            }
            else {
                mapp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < r+1; i++) {
        for (int j = 1; j < c+1; j++) {
            bfs_num[i][j] = white;
        }
    }
    int testcase;
    cin >> testcase;
    
    
}