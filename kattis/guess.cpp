#include<bits/stdc++.h>
using namespace std;

int main() {
    int lb = 1;
    int ub = 1000;
    while (true) {
        int mid = (lb + ub) / 2;
        cout << mid << endl;
        cout << flush;
        string c;
        cin >> c;
        if (c == "lower") {
            ub = mid - 1;
        } else if (c == "higher") {
            lb = mid + 1;
        } else {
            break;
        }
    }
}