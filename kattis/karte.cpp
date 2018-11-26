#include <bits/stdc++.h>
using namespace std;

int main() {
	string lst;
	cin >> lst;
	unordered_map<char, unordered_set<string>> deck;
	unordered_map<char, int> saver;
	saver['P'] = 13;
	saver['K'] = 13;
	saver['H'] = 13;
	saver['T'] = 13;
	bool err = false;
	for (int i = 0; i < lst.length(); i+=3) {
		if (deck[lst[i]].find(lst.substr(i+1, 2)) == deck[lst[i]].end()) {
			saver[lst[i]]--;
			deck[lst[i]].insert(lst.substr(i+1, 2));
		}
		else {
			err = true;
			break;
		}
	}
	if (err) {
		cout << "GRESKA"<< endl;
	}
	else {
		cout << saver['P'] << ' ' << saver['K'] << ' ' << saver['H'] << ' ' << saver['T'] << endl;
	}
}