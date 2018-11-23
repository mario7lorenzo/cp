#include <bits/stdc++.h>
using namespace std;

#define white -1
#define black 1

int mapp[1020][1020];
int color = 0;
unordered_map<int, vector<int>> al;
unordered_set<int> saver;
int dfs_num[1000050];

void dfs(int x, int color) {
    dfs_num[x] = color;
    for (int i = 1; i < al[x].size(); i++) {
        int vtx = al[x][i];
        if (dfs_num[vtx] == white) {
            dfs(vtx, color);
        }
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
            int tipe = mapp[i][j];
            int ind = ((i-1)*c)+j;
            al[ind].push_back(-1);
            if (mapp[i][j-1]==tipe) {
                al[ind].push_back(ind-1);
            }
            if (mapp[i][j+1]==tipe) {
                al[ind].push_back(ind+1);
            }
            if (mapp[i-1][j]==tipe) {
                al[ind].push_back(ind-c);
            }
            if(mapp[i+1][j]==tipe) {
                al[ind].push_back(ind+c);
            }
        }
    }
    for (int i = 0; i < (r*c)+2; i++) {
    	dfs_num[i] = white;
    }
    for (int i = 1; i < (r*c)+1; i++) {
    	if (dfs_num[i] == white) {
    		dfs(i, color);
    		color++;
    	}
    }
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        int x1, y1, x2, y2, coor1, coor2;
        cin >> x1 >> y1 >> x2 >> y2;
        coor1 = ((x1-1)*c)+y1;
        coor2 = ((x2-1)*c)+y2;
        if (dfs_num[coor1] == dfs_num[coor2]) {
        	if (mapp[x1][y1]) {
        		cout << "decimal" << endl;
        	}
        	else {
        		cout << "binary" << endl;
        	}
        }
        else {
        	cout << "neither" << endl;
        }
    }
}