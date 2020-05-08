#include <bits/stdc++.h>
using namespace std;

string encrypt(string x) {
	string final = "";
	for (auto i : x) {
		if (i != ' ') {
			if (!(int(i) >= 65 && int(i) <= 90)) {
				i = char(int(i)-32);
			}
			final += i;
		}
	}
	int pivot = 0;
	string temp = "";
	while (pivot < final.length()) {
		if (pivot == final.length()-1) {
			temp += final[pivot];
			temp += 'X';
			pivot++;
		}
		else if (final[pivot] == final[pivot+1]) {
			temp += final[pivot];
			temp += 'X';
			pivot++;
		}
		else {
			temp += final[pivot];
			temp += final[pivot+1];
			pivot += 2;
		}
	}
	if (temp.length()%2) {
		temp += 'X';
	}
	return temp;
}

char grid[5][5];

void cipher(string x) {
	bool already[26];
	for (int i = 0; i < 26; i++) {
		already[i] = true;
	}
	int a = 0, b = 0;
	for (auto i : x) {
		if (i != ' ') {
			char t = char(int(i)-32);
			if (already[int(t)-65]) {
				grid[a][b] = t;
				b++;
				if (b == 5) {
					a++;
					b = 0;
				}
				already[int(t)-65] = false;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		if (already[i] && i != 16) {
			grid[a][b] = char(65+i);
			b++;
			if (b == 5) {
				a++;
				b = 0;
			}
		}
	}
}
int main() {
	string cip, mes;
	getline(cin, cip);
	getline(cin, mes);
	string enc = encrypt(mes);
	cipher(cip);
	string final = "";
	int pivot = 0;
	while (pivot < enc.length()) {
		char a = enc[pivot], b = enc[pivot+1];
		int ax, ay, bx, by;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (grid[i][j] == a) {
					ax = i;
					ay = j;
				}
				if (grid[i][j] == b) {
					bx = i;
					by = j;
				}
			}
		}
		if (ax == bx) {
			final += grid[ax][(ay+1)%5];
			final += grid[bx][(by+1)%5];
		}
		else if (ay == by) {
			final += grid[(ax+1)%5][ay];
			final += grid[(bx+1)%5][by];
		}
		else {
			final += grid[ax][by];
			final += grid[bx][ay];
		}
		pivot += 2;
	}
	cout << final << endl;
}