#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        string s, t;
        cin >> s >> t;
        int os = 0, zs = 0, qs = 0, ot = 0, zt = 0, counter = 0, ptr = 0;
        bool can = true;
        int len = s.length();
        for (int j = 0; j < len; j++) {
            if (s[j] == '0') {
                zs++;
            } else if (s[j] == '1') {
                os++;
            } else {
            	qs++;
            }
        }
        for (int j = 0; j < len; j++) {
            if (t[j] == '0') {
                zt++;
            } else {
                ot++;
            }
        }
        for (int j = 0; j < len; j++) {
            if (s[j] == '?') {
                if (t[j] == '1' && os != ot) {
                    s[j] = '1';
                    os++;
                } else {
                    s[j] = '0';
                    zs++;
                }
                counter++;
                qs--;
            }
        }
        cout << "Case " << i << ": ";
        while (os < ot && zs > zt) {
            if (ptr == len) {
                ptr = 0;
                while (os < ot && zs > zt && ptr < len) {
                    if (s[ptr] == '0') {
                        s[ptr] = '1';
                        os++;
                        zs--;
                        counter++;
                    }
                    ptr++;
                }
                break;
            }
            if (s[ptr] == '0' && t[ptr] == '1') {
                s[ptr] = '1';
                os++;
                zs--;
                counter++;
            }
            ptr++;
        }
        if (os == ot && zs == zt) {
            int mismatch = 0;
            for (int j = 0; j < len; j++) {
                if (s[j] != t[j]) {
                    mismatch++;
                }
            }
            counter += mismatch/2;
            cout << counter << endl;
        } else {
            cout << -1 << endl;
        }
    }
}