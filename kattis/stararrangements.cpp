#include <bits/stdc++.h>
using namespace std;

int main() {
    int states;
    cin >> states;
    cout << states << ":" << endl;
    for (int i = 2; i < (round((states/2) + 0.5)+1); i++) {
        if ((states+i-1)%(2*i-1) == 0) {
            cout << i << ',' << i-1 << endl;
        }
        else if (states%(2*i-1) == 0) {
            cout << i << ',' << i-1 << endl;
        }
        if (states%(2*i) == 0) {
            cout << i << ',' << i << endl;
        }
        else if ((states+i)%(2*i) == 0) {
            cout << i << ',' << i << endl;
        }
    }
}