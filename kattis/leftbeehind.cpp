#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, q;
    while (cin >> p >> q, p | q) {
        if (p + q == 13) {
            cout << "Never speak again." << endl;
        }
        else if (p == q) {
            cout << "Undecided." << endl;
        }
        else if (p > q) {
            cout << "To the convention." << endl;
        }
        else if (p < q) {
            cout << "Left beehind." << endl;
        }
    }
}