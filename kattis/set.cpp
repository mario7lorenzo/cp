#include <bits/stdc++.h>
using namespace std;

bool is_set(pair<pair<char, char>, pair<char, char>> x, pair<pair<char, char>, pair<char, char>> y, pair<pair<char, char>, pair<char, char>> z) {
	char a = x.first.first, b = y.first.first, c = z.first.first;
	if ((a == b && b == c) || (a != b && b != c && a != c)) {
		char d = x.first.second, e = y.first.second, f = z.first.second;
		if ((d == e && e == f) || (d != e && e != f && d != f)) {
			char g = x.second.first, h = y.second.first, i = z.second.first;
			if ((g == h && h == i) || (g != h && h != i && g != i)) {
				char j = x.second.second, k = y.second.second, l = z.second.second;
				if ((j == k && k == l) || (j != k && j != l && k != l)) {
					return true;
				}
			}
		}
	}
	return false;
} 

int main() {
	unordered_map<int, pair<pair<char, char>, pair<char, char>>> saver;
	for (int i = 1; i <= 12; i++) {
		string chr;
		cin >> chr;
		saver[i] = make_pair(make_pair(chr[0], chr[1]), make_pair(chr[2], chr[3]));
	}
	vector<pair<int, pair<int, int>>> lst;
	for (int i = 1; i <= 12; i++) {
		for (int j = i+1; j <= 12; j++) {
			for (int k = j+1; k <= 12; k++) {
				pair<pair<char, char>, pair<char, char>> uno = saver[i], dos = saver[j], tres = saver[k];
				if (is_set(uno, dos, tres)) {
					lst.emplace_back(i, make_pair(j, k));
				}
			}
		}
	}
	sort(lst.begin(), lst.end());
	if (lst.size() == 0) {
		cout << "no sets" << endl;
	}
	else {	
		for (auto i : lst) {
			cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
		}
	}
}