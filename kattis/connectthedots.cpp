#include <bits/stdc++.h>
using namespace std;

bool cuscom (pair<int, pair<int, int>> x, pair<int, pair<int, int>> y) {
	return x.first < y.first;
}
int main() {
	string init;
	bool isfirst = true;
	string aux;
	while (getline(cin, init)) {
		if (isfirst) {
			isfirst = false;
		}
		else {
			cout << endl;
		}
		// cout << "ini init " << init << endl;
		vector<pair<int, pair<int, int>>> coor;
		vector<string> saver;
		saver.push_back(init);
		while (getline(cin, aux)) {
			// cout << "ini aux " << aux << endl;
			if (aux == "") {
				break;
			}
			saver.push_back(aux);
		}
		int row = saver.size();
		int col = saver[0].size();
		char arr[row][col];
		for (int i = 0; i < saver.size(); i++) {
			for (int j = 0; j < saver[i].length(); j++) {
				if (saver[i][j] != '.') {
					pair<int, int> pl = make_pair(i, j);
					pair<int, pair<int, int>> fin;
					if (int(saver[i][j]) >= 48 && int(saver[i][j]) <= 57) {
						fin = make_pair(int(saver[i][j])-48, pl);
					}
					else if (int(saver[i][j]) >= 97 && int(saver[i][j]) <= 122) {
						fin = make_pair(int(saver[i][j])-87, pl);
					}
					else if (int(saver[i][j]) >= 65 && int(saver[i][j]) <= 90) {
						fin = make_pair(int(saver[i][j])-29, pl);
					}
					coor.push_back(fin);				
				}
				arr[i][j] = saver[i][j];
			}
		}
		sort(coor.begin(), coor.end(), cuscom);
		for (int i = 1; i < coor.size(); i++) {
			int x1, y1, x2, y2, dist;
			// cout << "ini skrg " << coor[i-1].first << ' ' << coor[i].first << endl; 
			x1 = coor[i-1].second.first;
			y1 = coor[i-1].second.second;
			x2 = coor[i].second.first;
			y2 = coor[i].second.second;
			if (x1 == x2) {
				// cout << "x sama " << y1  << ' ' << y2 << endl;
				if (y1 < y2) {
					for (int i = y1+1; i < y2; i++) {
						if (arr[x1][i] == '.') {
							arr[x1][i] = '-';
						}
						else if (arr[x1][i] == '|') {
							arr[x1][i] = '+';
						}
					}
				}
				else if (y1 > y2) {
					for (int i = y1-1; i > y2; i--) {
						if (arr[x1][i] == '.') {
							arr[x1][i] = '-';
						}
						else if (arr[x1][i] == '|') {
							arr[x1][i] = '+';
						}
					}
				}
			}
			else if (y1 == y2) {
				// cout << "y sama " << x1 << ' ' << x2 << endl;
				if (x1 < x2) {
					for (int i = x1+1; i < x2; i++) {
						if (arr[i][y1] == '.') {
							arr[i][y1] = '|';
						}
						else if (arr[i][y1] == '-') {
							arr[i][y1] = '+';
						}
					}
				}
				else if (x1 > x2) {
					for (int i = x1-1; i > x2; i--) {
						if (arr[i][y1] == '.') {
							arr[i][y1] = '|';
						}
						else if (arr[i][y1] == '-') {
							arr[i][y1] = '+';
						}
					}
				}
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << arr[i][j];
			}
			cout << endl;
		}
	}
}