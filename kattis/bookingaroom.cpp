#include <bits/stdc++.h>
using namespace std;

bool linsearch(int x, vector<int> y) {
    int sz = y.size();
    bool verifier = false;
    for (int i = 0; i < sz; i++) {
        if (y[i] == x) {
            verifier = true;
            break;
        }
    }
    return verifier;
}
int main() {
    int r, n;
    cin >> r >> n;
    if (r == n) {
        cout << "too late" << endl;
    }
    else if (n == 0) {
        cout << 1 << endl;
    }
    else {
        vector<int> lst;
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            lst.push_back(p);
        }
        for (int i = 1; i <= r; i++) {
            if (linsearch(i, lst) == false) {
                cout << i << endl;
                break;
            }
        }
    }
}