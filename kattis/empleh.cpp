#include <bits/stdc++.h>
using namespace std;

int colid(char x) {
	if (x == 'a') {
		return 0;
	}
	if (x == 'b') {
		return 1;
	}
	if (x == 'c') {
		return 2;
	}
	if (x == 'd') {
		return 3;
	}
	if (x == 'e') {
		return 4;
	}
	if (x == 'f') {
		return 5;
	}
	if (x == 'g') {
		return 6;
	}
	if (x == 'h') {
		return 7;
	}
}

int rowid(char x) {
	if (x == '8') {
		return 0;
	}
	if (x == '7') {
		return 1;
	}
	if (x == '6') {
		return 2;
	}
	if (x == '5') {
		return 3;
	}
	if (x == '4') {
		return 4;
	}
	if (x == '3') {
		return 5;
	}
	if (x == '2') {
		return 6;
	}
	if (x == '1') {
		return 7;
	}
}

int main() {
	string dumw, w, dumb, b;
	getline(cin, w);
	getline(cin, b);
	w = w.substr(7);
	b = b.substr(7);
	vector<vector<string>> saver;
	vector<string> white, black;
	w += ',';
	b += ',';
	string temp = "";
	for (int i = 0; i < w.length(); i++) {
		if (w[i] == ',') {
			white.push_back(temp);
			temp = "";
		}
		else {
			temp += w[i];
		}
	}
	for (int i = 0; i < b.length(); i++) {
		if (b[i] == ',') {
			black.push_back(temp);
			temp = "";
		}
		else {
			temp += b[i];
		}
	}
	for (int i = 0; i < 8; i++) {
		vector<string> temp;
		if (i%2 == 0) {
			for (int j = 0; j < 8; j++) {
				if (j%2 == 0) {
					temp.push_back("...");
				}
				else {
					temp.push_back(":::");
				}
			}
		}
		else {
			for (int j = 0; j < 8; j++) {
				if (j%2 == 0) {
					temp.push_back(":::");
				}
				else {
					temp.push_back("...");
				}
			}
		}
		saver.push_back(temp);
	}
	for (int i = 0; i < white.size(); i++) {
		if (white[i].length() == 3) {
			int row = rowid(white[i][2]), col = colid(white[i][1]);
			if (saver[row][col] == ":::") {
				saver[row][col] = ":";
				saver[row][col] += white[i][0];
				saver[row][col] += ":";
			}
			else if (saver[row][col] == "...") {
				saver[row][col] = ".";
				saver[row][col] += white[i][0];
				saver[row][col] += ".";
			}
		}
		else if (white[i].length() == 2) {
			int row = rowid(white[i][1]), col = colid(white[i][0]);
			if (saver[row][col] == ":::") {
				saver[row][col] = ":P:";
			}
			else if (saver[row][col] == "...") {
				saver[row][col] = ".P.";
			}
		}
	}
	for (int i = 0; i < black.size(); i++) {
		if (black[i].length() == 3) {
			int row = rowid(black[i][2]), col = colid(black[i][1]);
			if (saver[row][col] == ":::") {
				saver[row][col] = ":";
				saver[row][col] += char(black[i][0]+32);
				saver[row][col] += ':';
			}
			else if (saver[row][col] == "...") {
				saver[row][col] = ".";
				saver[row][col] += char(black[i][0]+32);
				saver[row][col] += '.';
			}
		}
		else if (black[i].length() == 2) {
			int row = rowid(black[i][1]), col = colid(black[i][0]);
			if (saver[row][col] == ":::") {
				saver[row][col] = ":p:";
			}
			else if (saver[row][col] == "...") {
				saver[row][col] = ".p.";
			}
		}
	}
	cout << "+---+---+---+---+---+---+---+---+" << endl;
	for (int i = 0; i < saver.size(); i++) {
		cout << '|';
		for (int j = 0; j < saver[i].size(); j++) {
			cout << saver[i][j] << '|';
		}
		cout << endl;
		cout << "+---+---+---+---+---+---+---+---+" << endl;
	}
}