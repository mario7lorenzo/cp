#include <bits/stdc++.h>
using namespace std;
bool custcoma (pair<int, int> x, pair<int, int> y) {
    return x.second < y.second;
}

bool custcomb (pair<int, int> x, pair<int, int> y) {
    return x.first < y.first;
}

int main() {
    bool isfir = true;
    int p;
    while (cin >> p, p) {
        if (isfir) {
            isfir = false;
        }
        else {
            cout << endl;
        }
        vector<pair<int, int>> first;
        vector<pair<int, int>> second;
        for (int i = 0; i < p; i++) {
            int val;
            cin >> val;
            pair<int, int> sementara;
            sementara = make_pair(i, val);
            first.push_back(sementara);
        }
        sort(first.begin(), first.end(), custcoma);
        for (int i = 0; i < p; i++) {
            int val;
            cin >> val;
            pair<int, int> sementara;
            sementara = make_pair(0, val);
            second.push_back(sementara);
        }
        sort(second.begin(), second.end(), custcoma);
        for (int i = 0; i < second.size(); i++) {
            second[i].first = first[i].first;
        }
        sort(second.begin(), second.end(), custcomb);
        for (int i = 0; i < second.size(); i++) {
            cout << second[i].second << endl;
        }
    }
}