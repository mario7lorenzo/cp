#include <bits/stdc++.h>
using namespace std;

int main() {
    int panjang;
    cin >> panjang;
    vector<int> lst;
    for (int i = 0; i < panjang; i++) {
        int p;
        cin >> p;
        lst.push_back(p);
    }
    int vimax = -1e9;
    int vimin = 1e9;
    vector<int> maxi(panjang);
    vector<int> mini(panjang);
    for (int i = 0; i < panjang; i++) {
        vimax = max(vimax, lst[i]);
        maxi[i] = vimax;
    }
    for (int i = panjang-1; i >= 0; i--) {
        vimin = min(vimin, lst[i]);
        mini[i] = vimin;
    }
    // for (int x: lst) cout << x << ' ';
    //  cout << endl;
    // for (int x: maxi) cout << x << ' ';
    //  cout << endl;
    // for (int x: mini) cout << x << ' ';
    //  cout << endl;
    mini.push_back(1e9);
    int counter = 0;
    for (int i = 0; i < panjang; i++) {
        if (maxi[i] <= lst[i] && mini[i+1] > lst[i]) {
            counter++;
        }
    }
    cout << counter << endl;
}