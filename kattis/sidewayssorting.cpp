#include <bits/stdc++.h>
using namespace std;
bool comp(string a, string b) {
    for (int i = 0; i < a.length(); i++) {
        if (a[i]%32 == b[i]%32) 
            continue;
        if (a[i]%32 < b[i]%32) 
            return true;
        if (a[i]%32 > b[i]%32) 
            return false;
    }
    return false;
}

int main() {
    bool is_first = true;
    int p, q;
    while(cin >> p >> q, p) {
        if (is_first) {
            is_first = false;
        }
        else {
            cout << endl;
        }
        vector<string> ori;
        vector<string> transposed;
        for (int i = 0; i < p; i++) {
            string words;
            cin >> words;
            ori.push_back(words);
        }
        for (int i = 0; i < q; i++) {
            string kntl = "";
            for (int j = 0; j < p; j++) {
                kntl += ori[j][i];
            }
            transposed.push_back(kntl);
        }
        ori.clear();
        stable_sort(transposed.begin(), transposed.end(), comp);
        for (int i = 0; i < p; i++) {
            string kntl = "";
            for (int j = 0; j < q; j++) {
                kntl += transposed[j][i];
            }
            cout << kntl << endl;
        }
    }
}