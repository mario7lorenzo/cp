#include <bits/stdc++.h>
using namespace std;
int chartoint(char x) {
    return x - 'A' + 1;
}
char inttochar(int x) {
    return 'A' + x - 1;
}

bool verifier(int x, int y) {
    if (x%2 != y%2) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        char x1, x2;
        int y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        vector<pair<int, int>> saver;
        int xawal = chartoint(x1);
        int xakhir = chartoint(x2);
        saver.emplace_back(xawal, y1);
        if (x1 == x2 && y1 == y2) {
            cout << 0 << ' ' << x1 << ' ' << y1 << endl;
        }
        else if (verifier(xawal, y1) != verifier(xakhir, y2)) {
            cout << "Impossible" << endl;
        } 
        else {
            int mv = 0;
            if ((xawal + y1 == xakhir + y2) || (xawal - y1 == xakhir - y2)) {
                cout << 1 << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl; 
            }
            else {
                int xposa = ((xawal + y1) + (xakhir-y2)) / 2;
                int yposa = (xawal + y1) - xposa;
                int xposb = ((xakhir + y2) + (xawal-y1)) / 2;
                int yposb = ((xakhir + y2)) - xposb;
                int xtrans, ytrans;
                if (xposa < 1 || xposa > 8 || yposa < 1 || yposa > 8) {
                    xtrans = xposb;
                    ytrans = yposb;
                }
                else {
                    xtrans = xposa;
                    ytrans = yposa;
                }
                cout << 2 << ' ' << x1 << ' ' << y1 << ' ' << inttochar(xtrans) << ' ' << ytrans << ' ' << x2 << ' ' << y2 << endl;
            }
        }   
    }
}