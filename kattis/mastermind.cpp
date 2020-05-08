#include <bits/stdc++.h>
using namespace std;

int main() {
	int pjg, r = 0, s = 0;
	string code, guess;
	cin >> pjg >> code >> guess;
	unordered_map<char, int> kantong1;
	unordered_multiset<char> kantong2;
	for (int i = 0; i < pjg; i++) {
		if (code[i] == guess[i]) {
			r++;
		}
		else {
			kantong2.insert(guess[i]);
			kantong1[code[i]]++;
		}
	}
	for (auto i : kantong2) {
		if (kantong1[i] != 0) {
			s++;
			kantong1[i]--;
		}
	}
	cout << r << ' ' << s << endl;
}