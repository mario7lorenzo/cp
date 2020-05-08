#include <bits/stdc++.h>
using namespace std;

int unk = 1e9;

int scan() {
	string x;
	cin >> x;
	if (x == "?") {
		return unk;
	}
	else {
		return stoi(x);
	}
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int play = scan(), win = scan(), draw = scan(), lose = scan(), pts = scan();
		if (play == unk && lose == unk) {
			lose = 0;
		}
		int wma, wmi, dma, dmi;
		if (win == unk) {
			wma = 100;
			wmi = 0;
		}
		else {
			wma = win;
			wmi = win;
		}
		if (draw == unk) {
			dma = 100;
			dmi = 0;
		}
		else {
			dma = draw;
			dmi = draw;
		}
		for (int i = wmi; i <= wma; i++) {
			for (int j = dmi; j <= dma; j++) {
				int plays, loses, ptss;
				if (play == unk) {
					plays = i + j + lose;
				}
				else {
					plays = play;
				}
				if (lose == unk) {
					loses = plays - i - j;
				}
				else {
					loses = lose;
				}
				if (pts == unk) {
					ptss = 3*i + j;
				}
				else {
					ptss = pts;
				}
				if (plays == i + j + loses && plays <= 100 && plays >= 0 && loses <= 100 && loses >= 0 && ptss == 3*i + j) {
					cout << plays << ' ' << i << ' ' << j << ' ' << loses << ' ' << ptss << endl;
				}
			}
			
		}
	}
}