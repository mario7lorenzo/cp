#include <bits/stdc++.h>
using namespace std;

int main() {
    int p;
    cin >> p;
    for (int i = 0; i < p; i++) {
        int r, e, c;
        cin >> r >> e >> c;
        if (e - r < c) {
            cout << "do not advertise" << endl;
        }
        else if (e-r > c) {
            cout << "advertise" << endl;
        }
        else {
            cout << "does not matter" << endl;
        }
    }
}