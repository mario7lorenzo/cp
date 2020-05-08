#include <bits/stdc++.h>
using namespace std;

int main() {
    string m, d, y, r, s;
    while (cin >> m >> d >> y >> r >> s) {
        int rh, sh, rm, sm; 
        if (r.length() == 4) {
            rh = stoi(r.substr(0, 1));
            rm = stoi(r.substr(2, 2));
        }
        else {
            rh = stoi(r.substr(0, 2));
            rm = stoi(r.substr(3, 2));
        }    
        if (s.length() == 4) {
            sh = stoi(s.substr(0, 1));
            sm = stoi(s.substr(2, 2));
        }
        else {
            sh = stoi(s.substr(0, 2));
            sm = stoi(s.substr(3, 2));
        }
        int finalh = sh - rh;
        int finalm = sm - rm;
        if (finalm < 0) {
            finalm += 60;
            finalh --;
        }
        cout << m << " "  << d << " " << y << " " << finalh << " hours " << finalm << " minutes " << endl;
    }
}