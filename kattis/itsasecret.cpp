#include <bits/stdc++.h>
using namespace std;

string message;

void encrypt() {
	string temp = "";
	for (auto i : message) {
		char x = i;
		if (i != ' ') {
			if (!(int(i) >= 65 && int(i) <= 90)) {
				x = char(int(i)-32);
			}
			if (x == 'J') {
				x = 'I';
			}
			temp += x;
		}
	}
	string final = "";
	int pivot = 0;
	while (pivot < temp.length()) {
		if (pivot == temp.length()-1) {
			final += temp[pivot];
			pivot++;
		}
		else if (temp[pivot] == temp[pivot+1]) {
			if (temp[pivot] == 'X') {
				final += "XX";
				pivot++;
			}
			else {
				final += temp[pivot];
				final += 'X';
				pivot++;
			}
		}
		else {
			final += temp[pivot];
			final += temp[pivot+1];
			pivot += 2;
		}
	}
	if (final.length()%2) {
		final += 'X';
	}
	message = final;
}

int main() {
	int tc;
	bool isfirst = true;
	while (cin >> tc, tc) {
		if (isfirst) {
			isfirst = false;
		}
		else {
			cout << endl;
		}
		// cout << tc << endl;
		cin.ignore();
		string st;
		getline(cin, st);
		// cout << st << endl;
		char grid[5][5];
		bool already[27];
		for (int i = 0; i < 27; i++) {
			already[i] = true;
		}
		int x = 0, y = 0;
		for (auto i : st) {
			int ind = int(i);
			if (ind >= 97 && ind <= 122) {
				ind -= 32;
			}
			char now = char(ind);
			if ((int(now) >= 65 && int(now) <= 90)) {
				if (now == 'J') {
					now = 'I';
				}
				if (already[int(now) - 65]) {
					grid[x][y] = now;
					already[int(now)-65] = false;
					y++;
					if (y == 5) {
						x++;
						y = 0;
					} 					
				}
			}
		}
		for (int i = 0; i < 27; i++) {
			if (already[i] && i != 9) {
				grid[x][y] = char(i+65);
				y++;
				if (y == 5) {
					x++;
					y = 0;
				}
			}
		}
		while (tc--) {
			getline(cin, message);
			encrypt();
			// cout << message << endl;
			string final = "";
			for (int i = 0; i < message.length(); i+=2) {
				char digone = message[i], digtwo = message[i+1];
				if (digone == digtwo && digone == 'X') {
					final += "YY";
				}
				else {
					int digonex, digoney, digtwox, digtwoy;
					for (int i = 0; i < 5; i++) {
						for (int j = 0; j < 5; j++) {
							if (grid[i][j] == digone) {
								digonex = i;
								digoney = j;
							}
							if (grid[i][j] == digtwo) {
								digtwox = i;
								digtwoy = j;
							}
						}
					}
					if (digonex == digtwox) {
						if (digoney == 4) {
							final += grid[digonex][0];
						}
						else {
							final += grid[digonex][digoney+1];
						}
						if (digtwoy == 4) {
							final += grid[digtwox][0];
						}
						else {
							final += grid[digtwox][digtwoy+1];
						}
					}
					else if (digoney == digtwoy) {
						if (digonex == 4) {
							final += grid[0][digoney];
						}
						else {
							final += grid[digonex+1][digoney];
						}
						if (digtwox == 4) {
							final += grid[0][digtwoy];
						}
						else {
							final += grid[digtwox+1][digtwoy];
						}
					}
					else {
						int ax, ay, bx, by;
						ax = digonex;
						ay = digtwoy;
						bx = digtwox;
						by = digoney;
						final += grid[ax][ay];
						final += grid[bx][by];
					}
				}					
			}
			cout << final << endl;
		}
	}
}