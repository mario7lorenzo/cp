#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef pair<int, int> ii;

int main() {
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int sets;
        cin >> sets;
        int num, denom;
        char dummy;
        cin >> num >> dummy >> denom;
        int simpenatas = num;
        int simpenbawah = denom;

        if (denom == 1) {
            cout << sets << ' ' << "1/" << num + 1 << endl;
            continue;
        }
        int p = num;
        int q = denom;
        num = p % q;
        int jarak = p / q;
        // cout << num << " " << denom << endl;
        denom -= num;
        // cout << num << " " << denom << endl;
        num += denom;
        // cout << num << " " << denom << endl;
        denom += num * jarak;
        // cout << num << " " << denom << endl;
        cout << sets << ' ' << num << '/' << denom << endl;
    }
}