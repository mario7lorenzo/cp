#include <bits/stdc++.h>
using namespace std;

int main() {
    int p;
    vector<int> xlst;
    vector<int> ylst;
    while (cin >> p, p) {
        xlst.clear();
        ylst.clear();
        for (int i = 0; i < p; i++) {
            int x, y;
            cin >> x >> y;
            xlst.push_back(x);
            ylst.push_back(y);
        }
        xlst.push_back(xlst[0]);
        ylst.push_back(ylst[0]);
        double area = 0;
        for (int i = 0; i < xlst.size()-1; i++) {
            area += (xlst[i] * ylst[i+1]) - (xlst[i+1] * ylst[i]);
        }
        if (area < 0) {
            cout << "CW" << endl;
            cout << fixed << setprecision(1) << -(0.5 * area) << endl;
        }
        if (area > 0) {
            cout << "CCW" << endl;
            cout << fixed << setprecision(1) << 0.5 * area << endl;
        }
    }
}