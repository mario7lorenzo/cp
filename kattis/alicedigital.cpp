#include <bits/stdc++.h>
using namespace std;

int main() {
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        int n, m;
        cin >> n >> m;
        int pre = 0, aft = 0;
        int ctr = 0;
        int maxi = -1e7;
        int catetawal;
        int catetakhir;
        bool verify = true;
        int saver;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x < m) {
                maxi = max(pre, maxi);
                pre = 0;
                aft = 0;
                ctr = 0;
            }
            else {
                if (i == 0) {
                    catetawal = x;
                }
                if (i == n-1) {
                catetakhir = x;
                }
                if (m == x) {
                    if (i == 0) {
                        pre = x;
                        aft = x;
                        ctr++;
                    }
                    else if (ctr == 0) {
                        pre += x;
                        aft = x;
                        maxi = max(pre, maxi);
                        ctr++;
                    }
                    else {
                        maxi = max(maxi, pre);
                        pre = aft;
                        aft = x;
                        ctr++;
                    }
                }
                else {
                    pre += x;
                    aft += x;
                }
            }
        }
        if (ctr == 0) {
        	cout << maxi << endl;
        }
        if (ctr == 1) {
            if (catetawal == m) {
                int a;
                a = max(pre,aft);
                maxi = max(maxi, a);
                cout << maxi - catetakhir << endl; 
            }
            else if (catetakhir == m) {
                int a;
                a = max(pre,aft);
                maxi = max(maxi, a);
                cout << maxi - catetawal << endl;
            }
            else {
                int z, a;
                z = min(catetawal, catetakhir);
                a = max(pre, aft);
                maxi = max(maxi, a);
                cout << maxi-z << endl;
            }
        }
        else {
            int b;
            b = max(pre, aft);
            maxi = max(maxi, b);
            cout << maxi << endl;
        }
    }
}