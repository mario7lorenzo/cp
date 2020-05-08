#include <bits/stdc++.h>
using namespace std;

int main() {
    int hrs, mnt;
    cin >> hrs >> mnt;
    mnt -= 45;
    if (mnt < 0) {
        hrs -= 1;
        mnt += 60;
    }
    if (hrs < 0) {
        hrs += 24;
    }
    cout << hrs << " " << mnt << '\n';
}