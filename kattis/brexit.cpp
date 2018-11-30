#include <bits/stdc++.h>
using namespace std;

bool verifier[200100];
int neighbor[200100];
map<int, vector<int>> al;

int main() {
    int c, p, x, l;
    cin >> c >> p >> x >> l;
    for (int i = 0; i < c+2; i++) {
        verifier[i] = false;
        neighbor[i] = 0;
    }
    for (int i = 0; i < p; i++) {
        int a, y;
        cin >> a >> y;
        neighbor[a]++;
        neighbor[y]++;
        al[a].push_back(y);
        al[y].push_back(a);
    }
    verifier[l] = true;
    queue<int> q;
    for (int i = 0; i < al[l].size(); i++) {
        q.push(al[l][i]);
        neighbor[al[l][i]]--;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (!verifier[u]) {
            if (neighbor[u] <= al[u].size()/2) {
                verifier[u] = true;
                for (int i = 0; i < al[u].size(); i++) {
                    neighbor[al[u][i]]--;
                    q.push(al[u][i]);
                }
            }
        }
        
    }
    if (verifier[x]) {
        cout << "leave" << endl;
    }
    else {
        cout << "stay" << endl;
    }
}