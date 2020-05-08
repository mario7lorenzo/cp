#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, r;
    cin >> l >> r;
    if (l == 0 and r == 0) {
        cout << "Not a moose" << endl;
    }
    else if (l == r) {
        cout << "Even " << l * 2 << endl;
    }
    else {
        int highest = max(l, r);
        cout << "Odd " << highest * 2 << endl;
    }
}