#include <bits/stdc++.h>
using namespace std;

int id(char x) {
	if (x == 'k' | x== 'K') {
		return 5;
	}
	else if (x == 'q' | x == 'Q') {
		return 4;
	}
	else if (x == 'r' | x == 'R') {
		return 3;
	}
	else if (x == 'b' | x == 'B') {
		return 2;
	}
	else if (x == 'n' | x == 'N') {
		return 1;
	}
	else {
		return 0;
	}
}

char revid(int x) {
	if (x == 5) {
		return 'K';
	}
	else if (x == 4) {
		return 'Q';
	}
	else if (x == 3) {
		return 'R';
	}
	else if (x == 2) {
		return 'B';
	}
	else if (x == 1) {
		return 'N';
	}
}

bool cuscomw(pair<int, string> x, pair<int, string> y) {
	return x.second[1] < y.second[1];
}

bool cuscomb(pair<int, string> x, pair<int, string> y) {
	return x.second[1] > y.second[1];
}

bool cuscom1(pair<int, string> x, pair<int, string> y) {
	return x.second[0] < y.second[0];
}

bool cuscmai(pair<int, string> x, pair<int, string> y) {
	return x.first > y.first;
}

int main() {
	string p;
	vector<pair<int, string>> white;
	vector<pair<int, string>> black;
	int row = 9;
	while (getline(cin ,p)) {
		if (p == "+---+---+---+---+---+---+---+---+") {
			row--;
		}
		else {
			char col = 'a';
			for (int i = 2; i < p.length(); i+= 4) {
				if (p[i] != ':' && p[i] != '.') {
					if (int(p[i]) >= 97 && int(p[i]) <= 122) {
						black.emplace_back(id(p[i]), col + to_string(row));
					}
					else if (int(p[i]) >= 65 && int(p[i]) <= 90) {
						white.emplace_back(id(p[i]), col + to_string(row));
					}
				}
				col = char(col+1);
			}
		}
	}
	stable_sort(white.begin(), white.end(), cuscom1);
	stable_sort(white.begin(), white.end(), cuscomw);
	stable_sort(white.begin(), white.end(), cuscmai);
	stable_sort(black.begin(), black.end(), cuscom1);
	stable_sort(black.begin(), black.end(), cuscomb);
	stable_sort(black.begin(), black.end(), cuscmai);
	cout << "White: ";
	for (int i = 0; i < white.size(); i++) {
		if (i == 0) {
			if (white[i].first != 0) {
				cout << revid(white[i].first) << white[i].second;
			}
			else {
				cout << white[i].second;
			}
		}
		else {
			if (white[i].first != 0) {
				cout << "," << revid(white[i].first) << white[i].second;
			}
			else {
				cout << ',' << white[i].second;
			}
		}	
	}
	cout << endl;
	cout << "Black: ";
	for (int i = 0; i < black.size(); i++) {
		if (i == 0) {
			if (black[i].first != 0) {
				cout << revid(black[i].first) << black[i].second;
			}
			else {
				cout << black[i].second;
			}
		}
		else {
			if (black[i].first != 0) {
				cout << "," << revid(black[i].first) << black[i].second;
			}
			else {
				cout << ',' << black[i].second;
			}
		}		
	}
	cout << endl;
}