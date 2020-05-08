#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, c;
	cin >> r >> c;
	char arr[r][c];
	set<string> lst;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char x;
			cin >> x;
			arr[i][j] = x;
		} 
	}
	for (int i = 0; i < r; i++) {
		string temp = "";
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == '#') {
				if (temp.length() > 1) {
					lst.insert(temp);
				}
				temp = "";
			}
			else {
				temp += arr[i][j];
			}
		}
		if (temp.length() > 1) {
			lst.insert(temp);
		}
	}
	for (int i = 0; i < c; i++) {
		string temp = "";
		for (int j = 0; j < r; j++) {
			if (arr[j][i] == '#') {
				if (temp.length() > 1) {
					lst.insert(temp);
				}
				temp = "";
			}
			else {
				temp += arr[j][i];
			}
		}
		if (temp.length() > 1) {
			lst.insert(temp);
		}
	}
	for (auto i : lst) {
		cout << i << endl;
		break;
	}
}