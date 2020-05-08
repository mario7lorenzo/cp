#include <bits/stdc++.h>
using namespace std;

int main() {
    int counter = 0, x;
    while (cin >> x) {
        counter += 1;
        int minim = 1e9;
        int maxim = -1e9;
        for (int i = 0; i < x; i++) {
            int z;
            cin >> z;
            minim = min(minim, z);
            maxim = max(maxim, z);
        }
        int rng = maxim - minim;
        cout << "Case " << counter << ": "  << minim << " " << maxim << " " << rng << endl;  
    }
}