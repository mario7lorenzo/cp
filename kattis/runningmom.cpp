#include <bits/stdc++.h>
using namespace std;

#define white 1
#define black -1
#define gray 2

unordered_map<int, vector<int>> al;
int dfs_num[5050];
int cycle;
unordered_map<string, int> nodes;
int n = 0;

int getid(string x) {
    if (nodes.find(x) == nodes.end()) {
        nodes[x] = n;
        n++;
    }
    return nodes[x];
}

void cyclechecker(int city) {
    dfs_num[city] = gray;
    for (int i = 0 ; i < al[city].size(); i++) {
        if (dfs_num[al[city][i]] == white) {
            cyclechecker(al[city][i]);
        }
        else if (dfs_num[al[city][i]] == gray) {
            cycle = 1;
        }
    }
    dfs_num[city] = black;
}

int main() {
    int road;
    cin >> road;
    int noter = 0;
    for (int i = 0; i < road; i++) {
        string a, b;
        cin >> a >> b;
        al[getid(a)].push_back(getid(b));
    }
    string tst;
    while (cin >> tst) {
        cycle = 0;
        for (int i = 0; i < 5050; i++) {
            dfs_num[i] = white;
        }
        cyclechecker(getid(tst));
        cout << tst << ' ';
        if (!cycle) {
            cout << "trapped" << endl;
        }
        else {
            cout << "safe" << endl;
        }
    }
}