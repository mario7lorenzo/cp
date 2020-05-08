#include <bits/stdc++.h>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> grid;
    int steps = 0;
    for (int i = 0; i < row; i++) {
        vector<int> c;
        grid.push_back(c);
        for (int j = 0; j < col; j++) {
            char p;
            cin >> p;
            grid[i].push_back(p);
        }
    }
    int i = 0, j = 0;
    char pos;
    pos = grid[i][j];
    while (pos != 'T') {
        steps += 1;
        if (pos == 'X') {
            cout << "Lost" << endl;
            break;
        }
        else if (pos == 'E') {
            grid[i][j] = 'X';
            j += 1;
        }
        else if (pos == 'W') {
            grid[i][j] = 'X';
            j -= 1;
        }
        else if (pos == 'N') {
            grid[i][j] = 'X';
            i -= 1; 
        }
        else if (pos == 'S') {
            grid[i][j] = 'X';
            i += 1;         
        }
        if (i + 1 > row || j + 1 > col || i < 0 || j < 0) {
            cout << "Out" << endl;
            break;
        }
        pos = grid[i][j];       
    }
    if (pos == 'T') {
        cout << steps << endl;
    }
}