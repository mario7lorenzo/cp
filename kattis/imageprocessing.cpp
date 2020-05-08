#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w, n, m;
	cin >> h >> w >> n >> m;
	int img[h][w];
	vector<vector<int>> kernel;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int x;
			cin >> x;
			img[i][j] = x;
		}
	}
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			temp.push_back(x);
		}
		kernel.push_back(temp);
	}
	// reversing the kernel
	for (int i = 0; i < n; i++) {
		reverse(kernel[i].begin(), kernel[i].end());
	}
	reverse(kernel.begin(), kernel.end());
	int atasbawah = h-n+1, kirikanan = w-m+1;
	int y1 = 0, y2 = n;
	for (int i = 0; i < atasbawah; i++) {
		int x1 = 0, x2 = m;
		bool isfi = true;
		for (int j = 0; j < kirikanan; j++) {
			int counter = 0;
			int xkernel = 0, ykernel = -1;
			for (int k = y1; k < y2; k++) {
				ykernel++;
				for (int l = x1; l < x2; l++) {
					counter += (img[k][l]*kernel[ykernel][xkernel]);
					xkernel++;
				}
				xkernel = 0;
			}
			if (isfi) {
				cout << counter;
				isfi = false;
			}
			else {
				cout <<  ' ' << counter;
			}
			x1++;
			x2++;
		}
		cout << endl;
		y1 ++;
		y2 ++;
	}
}