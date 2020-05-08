#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grids;

void reversed() {
	for (int i = 0; i < 4; i++) {
		reverse(grids[i].begin(), grids[i].end());
	}
}

void transposed() {
	vector<vector<int>> temp;
	for (int i = 0; i < 4; i++) {
		vector<int> temp2;
		for (int j = 0; j < 4; j++) {
			temp2.push_back(grids[j][i]);
		}
		temp.push_back(temp2);
	}
	grids = temp;
}

void shifter() {
	vector<vector<int>> temp;
	for (int i = 0; i < 4; i++) {
		vector<int> semen;
		for (int j = 0; j < 4; j++) {
			if (grids[i][j] != 0) {
				semen.push_back(grids[i][j]);
			}
		}
		int uk = semen.size();
		while (uk < 4) {
			semen.push_back(0);
			uk++;
		}
		temp.push_back(semen);
	}
	grids = temp;
}

void mainop() {
	shifter();
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			if (grids[i][j-1] == grids[i][j]) {
				int otto = grids[i][j-1];
				grids[i][j-1] = 2*otto;
				grids[i][j] = 0;
			}
		}
	}
	shifter();
}

int main() {
	for (int i = 0; i < 4; i++) {
		vector<int> temp;
		for (int j = 0; j < 4; j++) {
			int num;
			cin >> num;
			temp.push_back(num);
		}
		grids.push_back(temp);
	}
	int op;
	cin >> op;
	if (op == 0) {
		mainop();
	}
	if (op == 1) {
		transposed();
		mainop();
		transposed();
	}
	if (op == 2) {
		reversed();
		mainop();
		reversed();
	}
	if (op == 3) {
		transposed();
		reversed();
		mainop();
		reversed();
		transposed();
	}
	for (int i = 0; i < 4; i++) {
		bool isfirst = true;
		for (int j = 0; j < 4; j++) {
			if (isfirst) {
				isfirst = false;
				cout << grids[i][j];
			}
			else {
				cout << ' ' << grids[i][j];
			}
		}
		cout << endl;
	}
}