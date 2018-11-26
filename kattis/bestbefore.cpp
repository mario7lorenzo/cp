#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> saver;

bool cuscom1(vector<int> x, vector<int> y) {
	return (x[0] < y[0]);
}

bool cuscom2(vector<int> x, vector<int> y) {
	return (x[1] < y[1]);
}

bool cuscom3(vector<int> x, vector<int> y) {
	return (x[2] < y[2]);
}

bool isleap(int x) {
	if (x % 400 == 0)
		return true;
	if (x % 100 == 0)
		return false;
	if (x % 4 == 0)
		return true;
	return false;
}

int main() {
	string dt;
	cin >> dt;
	string a = "", b = "", c = "", temp = "";
	for (int i = 0; i < dt.length(); i++) {
		if (dt[i] == '/') {
			if (a == "") {
				a = temp;
				temp = "";
			}
			else if (b == "") {
				b = temp;
				temp = "";
			}
		}
		else {
			temp += dt[i];
		}
	}
	c = temp;
	string pb[6][3];
	pb[0][0] = a;
	pb[0][1] = b;
	pb[0][2] = c;
	pb[1][0] = a;
	pb[1][1] = c;
	pb[1][2] = b;
	pb[2][0] = b;
	pb[2][1] = a;
	pb[2][2] = c;
	pb[3][0] = b;
	pb[3][1] = c;
	pb[3][2] = a;
	pb[4][0] = c;
	pb[4][1] = a;
	pb[4][2] = b;
	pb[5][0] = c;
	pb[5][1] = b;
	pb[5][2] = a;
	bool isthere = false;
	string df, mf, yf;
	for (int i = 0; i < 6; i++) {
		bool isdone = false;
		int dy = stoi(pb[i][0]), mt = stoi(pb[i][1]);
		string yr = pb[i][2];
		int lnt = yr.length();
		while (lnt < 4) {
			if (lnt == 3) {
				yr = '2' + yr;
				lnt++;
			}
			else {
				yr = '0' + yr;
				lnt++;
			}
		}
		int yrs = stoi(yr);
		if (yrs <= 2999) {
			if (mt >= 1 && mt <= 12) {
				if (isleap(yrs)) {
					if (mt == 1 || mt == 3 || mt == 5 || mt == 7 || mt == 8 || mt == 10 || mt == 12) {
						if (dy >= 1 && dy <= 31) {
							isdone = true;
							isthere = true;
						}
					}
					if (mt == 4 || mt == 6 || mt == 9 || mt == 11) {
						if (dy >= 1 && dy <= 30) {
							isdone = true;
							isthere = true;
						}
					}
					if (mt == 2) {
						if (dy >= 1 && dy <= 29) {
							isdone = true;
							isthere = true;
						}
					}
				}
				else {
					if (mt == 1 || mt == 3 || mt == 5 || mt == 7 || mt == 8 || mt == 10 || mt == 12) {
						if (dy >= 1 && dy <= 31) {
							isdone = true;
							isthere = true;
						}
					}
					if (mt == 4 || mt == 6 || mt == 9 || mt == 11) {
						if (dy >= 1 && dy <= 30) {
							isdone = true;
							isthere = true;
						}
					}
					if (mt == 2) {
						if (dy >= 1 && dy <= 28) {
							isdone = true;
							isthere = true;
						}
					}
				}
			}
		}
		if (isdone) {
			vector<int> temp;
			temp.push_back(dy);
			temp.push_back(mt);
			temp.push_back(yrs);
			saver.push_back(temp);
		}
	}
	sort(saver.begin(), saver.end(),cuscom1);
	sort(saver.begin(), saver.end(),cuscom2);
	sort(saver.begin(), saver.end(),cuscom3);
	if (isthere) {
		df = to_string(saver[0][0]);
		mf = to_string(saver[0][1]);
		yf = to_string(saver[0][2]);
		int tmp1 = df.length();
		int tmp2 = mf.length();
		while (tmp1 < 2) {
			df = '0' + df;
			tmp1++;
		}
		while (tmp2 < 2) {
			mf = '0' + mf;
			tmp2++;
		}
		cout << yf << '-' << mf << '-' << df << endl;
	}
	else {
		cout << dt << " is illegal" << endl;
	}
}