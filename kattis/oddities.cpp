#include <bits/stdc++.h>
using namespace std;

int main() {
    int p;
    cin >> p;
    for (int i = 0; i < p; i++) {
        int x;
        cin >> x;
        if (x%2) {
            cout << x << " is odd" << endl; 
        }
        else {
            cout << x << " is even" << endl;
        }
    }
}