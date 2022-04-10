#include <bits/stdc++.h>
using namespace std;

#define inf 1e9

vector<vector<pair<int, int>>> al;
priority_queue<pair<int, int>> pq;

int distKnight[100000];
int distDay[100000];

void dijkstraKnight(int source) {
    distKnight[source] = 0;

    pq.push(make_pair(distKnight[source], source));

    while (pq.size() > 0) {
        pair<int, int> p = pq.top();
        pq.pop();

        int w = -p.first;
        int u = p.second;
        
        // cout << "hi " << u << ' ' << w << ' ' << quota << endl;

        if (w > distKnight[u]) {
            continue;
        }

        for (pair<int, int> p : al[u]) {
            if (distKnight[u] < w) {
                continue;
            }
            int v = p.first;
            int weight = p.second;


            int total = distKnight[u] + weight;
            if (total < distKnight[v]) {
                distKnight[v] = total;
                pq.push(make_pair(-distKnight[v], v));
            }
        }
    }
}

void dijkstraDay(int source) {
    distDay[source] = 0;

    pq.push(make_pair(distDay[source], source));

    while (pq.size() > 0) {
        // cout << "jmbt" << endl;
        pair<int, int> p = pq.top();
        pq.pop();

        int w = -p.first;
        int u = p.second;
        
        // cout << w << ' ' << u << ' ' << quota << endl;
        if (w > distDay[u]) {
            continue;
        }

        for (pair<int, int> p : al[u]) {
            if (distDay[u] < w) {
                continue;
            }
            int v = p.first;
            int weight = p.second;
            
            // cout << v << ' ' << weight << endl;
            int mod = distDay[u]%12;
            int total;

            if (mod + weight > 12) {
                total = distDay[u] + weight + (12 - mod);
            } else {
                total = distDay[u] + weight;
            }
            // cout << total << endl;

            if (total < distDay[v]) {
                distDay[v] = total;
                // cout << "hi " << v << ' ' << total << endl;
                pq.push(make_pair(-distDay[v], v));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> temp;
        al.push_back(temp);
    }

    for (int i = 0; i < m; i++) {
        int u,v,d;
        cin >> u >> v >> d;

        al[u].push_back(make_pair(v,d));
        al[v].push_back(make_pair(u,d));
    }

    for (int i = 0; i < 100000; i++) {
        distKnight[i] = inf;
        distDay[i] = inf;
    }

    dijkstraKnight(0);
    dijkstraDay(0);

    int durKnight = distKnight[n-1];
    int durDay = distDay[n-1];
    if (distKnight[n-1] > 12) {
        durKnight += (distKnight[n-1]%12 == 0 ? ((distKnight[n-1]/12)-1)*12 : (distKnight[n-1]/12)*12);
    }

    if (distDay[n-1] > 12) {
        durDay += (distDay[n-1]%12 == 0 ? ((distDay[n-1]/12)-1)*12 : (distDay[n-1]/12)*12);
    }
    cout << durDay - durKnight << endl;
}