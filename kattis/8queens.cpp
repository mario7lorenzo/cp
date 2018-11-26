#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<bool>> grids;
    int queencounter = 0;
    bool cek = false;
    for (int i = 0; i < 8; i++) {
        vector<bool> temp;
        for (int j = 0; j < 8; j++) {
            char dot;
            cin >> dot;
            if (dot == '.') {
                temp.push_back(false);
            }
            else {
            	queencounter++;
                temp.push_back(true);
            }
        }
        grids.push_back(temp);
    }
    if (queencounter != 8) {
    	cout << "invalid" << endl;
    }
    else {
	    for (int i = 0; i < 8; i++) {
	        for (int j = 0; j < 8; j++) {
	            if (grids[i][j]) {
	                int x, y;
	                x = i-1;
	                y = j;
	                while (x >= 0) {
	                    if (grids[x][y]) {
	                        cek = true;
	                        break;
	                    }
	                    x--;
	                }
	                x = i;
	                y = j-1;
	                while (y >= 0) {
	                    if (grids[x][y]) {
	                        cek = true;
	                        break;
	                    }
	                    y--;
	                }
	                x = i+1;
	                y = j;
	                while (x <= 7) {
	                    if (grids[x][y]) {
	                        cek = true;
	                        break;
	                    }
	                    x++;
	                }
	                x = i;
	                y = j+1;
	                while (y <= 7) {
	                    if (grids[x][y]) {
	                        cek = true;
	                        break;
	                    }
	                    y++;
	                }
	                x = i-1;
	                y = j-1;
	                while (x>=0 && y>=0) {
	                    if (grids[x][y]) {
	                        cek = true;
	                        break;
	                    }
	                    x--;
	                    y--;
	                }
	                x = i+1;
	                y = j-1;
	                while (x<=7 && y>=0) {
	                    if (grids[x][y]) {
	                        cek = true;
	                        break;
	                    }
	                    x++;
	                    y--;
	                }
	                x = i-1;
	                y = j+1;
	                while (x>=0 && y<=7) {
	                    if (grids[x][y]) {
	                        cek = true;
	                        break;
	                    }
	                    x--;
	                    y++;
	                }
	                x = i+1;
	                y = j+1;
	                while (x<=7 && y<=7) {
	                    if (grids[x][y]) {
	                        cek = true;
	                        break;
	                    }
	                    x++;
	                    y++;
	                }
	            }
	        }
	    }
	    if (cek) {
	        cout << "invalid" << endl;
	    }
	    else {
	        cout << "valid" << endl;
	    }
    }
}