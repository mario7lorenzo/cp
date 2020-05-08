#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string message;
	vector<vector<char>> decrypted, top, right, bottom, left;
	for (int i = 0; i < n; i++) {
		vector<char> temp1, temp2;
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			temp1.push_back(c);
			temp2.push_back('~');
		}
		decrypted.push_back(temp2);
		top.push_back(temp1);
	}
	for (int i = 0; i < n; i++) {
		vector<char> temp;
		for (int j = n-1; j >= 0; j--) {
			temp.push_back(top[j][i]);
		}
		right.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		vector<char> temp;
		for (int j = n-1; j >= 0; j--) {
			temp.push_back(right[j][i]);
		}
		bottom.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		vector<char> temp;
		for (int j = n-1; j >= 0; j--) {
			temp.push_back(bottom[j][i]);
		}
		left.push_back(temp);
	}
	int ind = 0;
	cin >> message;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (top[i][j] == '.') {
				top[i][j] = message[ind];
				ind++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (right[i][j] == '.') {
				right[i][j] = message[ind];
				ind++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (bottom[i][j] == '.') {
				bottom[i][j] = message[ind];
				ind++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (left[i][j] == '.') {
				left[i][j] = message[ind];
				ind++;
			}
		}
	}
	bool valid = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (top[i][j] != 'X') {
				if (decrypted[i][j] == '~') {
					decrypted[i][j] = top[i][j];
				} else {
					if (decrypted[i][j] != top[i][j]) {
						valid = false;
					}
				}
			}
			if (right[i][j] != 'X') {
				if (decrypted[i][j] == '~') {
					decrypted[i][j] = right[i][j];
				} else {
					if (decrypted[i][j] != right[i][j]) {
						valid = false;
					}
				}
			}
			if (bottom[i][j] != 'X') {
				if (decrypted[i][j] == '~') {
					decrypted[i][j] = bottom[i][j];
				} else {
					if (decrypted[i][j] != bottom[i][j]) {
						valid = false;
					}
				}
			}
			if (left[i][j] != 'X') {
				if (decrypted[i][j] == '~') {
					decrypted[i][j] = left[i][j];
				} else {
					if (decrypted[i][j] != left[i][j]) {
						valid = false;
					}
				}
			}
		}
	}
	message = "";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (decrypted[i][j] == '~') {
				valid = false;
				break;
			}
			message += decrypted[i][j];
		}
	}
	if (valid) {
		cout << message << endl;
	} else {
		cout << "invalid grille" << endl;
	}
}