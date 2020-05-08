#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int>>> saver;
int l, w;

void update() {
    for (int i = 0; i < saver.size(); i++) {
        // cout << "========================" << endl;
        pair<int, pair<int, int>> temp = saver[i];
        int offset = temp.first, interval = temp.second.first, speed = temp.second.second;
        // cout << "offset sebelom " << offset << endl;
        if (i%2 == 0) {
            offset += speed;
            // cout << "ini offset stlh " << offset << endl;
            while (offset >= interval) {
                offset -= interval;
            }
            // cout << "adjusted " << offset << endl;
        }
        else {
            offset -= speed;
            // cout << "ini offset stlh " << offset << endl;
            while (offset < 0) {
                offset += interval;
            }
            // cout << "adjusted " << offset << endl;
        }
        // cout << "offset sesudah " << offset << endl;
        // cout << "========================" << endl;
        saver[i] = make_pair(offset, make_pair(interval, speed));
    }
}

int main() {
    bool left = true;
    cin >> l >> w;
    bool safe = false;
    for (int k = 0; k < l; k++) {
        int o, d, s;
        cin >> o >> d >> s;
        if (k%2) {
            o = w-1 - o;
            while (o >= d) {
                o -= d;
            }
        }
        saver.emplace_back(o, make_pair(d, s));
    }
    int frogx, frogy = l;
    cin >> frogx;
    string op;
    cin >> op;
    for (auto i : op) {
        if (i == 'U') {
            frogy--;
        }
        else if (i == 'D') {
            frogy++;
        }
        else if (i == 'L') {
            frogx--;
        }
        else if (i == 'R') {
            frogx++;
        }
        if (frogy == -1) {
            safe = true;
            break;
        }
        update();
        if (frogy < l) {
            pair<int, pair<int, int>> temp = saver[frogy];
            int offset = temp.first, interval = temp.second.first, speed = temp.second.second;
			if (frogx >= offset) {
	            if ((frogx-offset)%interval == 0) {
	                safe = false;
	                break;
	            }				
			}   
        }    
    }
    if (safe) {
        cout << "safe" << endl;
    }
    else {
        cout << "squish" << endl;
    }
}