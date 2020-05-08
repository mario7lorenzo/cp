#include <bits/stdc++.h>
using namespace std;

int main() {
    int p;
    cin >> p;
    for (int i = 0; i < p; i++) {
        int vertex;
        vector<int> x;
        vector<int> y;
        cin >> vertex;
        for (int j = 0; j < 2 * vertex; j++) {
            int bayangan;
            cin >> bayangan;
            if (j % 2 == 0) {
                x.push_back(bayangan);
            }
            else {
                y.push_back(bayangan);
            }
        }
        x.push_back(x[0]);
        y.push_back(y[0]);
        float counter = 0.0;
        for (int k = 0; k < vertex; k++) {
            counter += ((x[k] * y[k+1]) - (x[k+1] * y[k]));
        }
        if (counter < 0) {
            cout << -counter/2 << endl;
        }
        else {
            cout << counter/2 << endl;
        }
    }
}