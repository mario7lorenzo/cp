#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<char, string> saver;
	saver['a'] = "2";
	saver['b'] = "22";
	saver['c'] = "222";
	saver['d'] = "3";
	saver['e'] = "33";
	saver['f'] = "333";
	saver['g'] = "4";
	saver['h'] = "44";
	saver['i'] = "444";
	saver['j'] = "5";
	saver['k'] = "55";
	saver['l'] = "555";
	saver['m'] = "6";
	saver['n'] = "66";
	saver['o'] = "666";
	saver['p'] = "7";
	saver['q'] = "77";
	saver['r'] = "777";
	saver['s'] = "7777";
	saver['t'] = "8";
	saver['u'] = "88";
	saver['v'] = "888";
	saver['w'] = "9";
	saver['x'] = "99";
	saver['y'] = "999";
	saver['z'] = "9999";
	saver[' '] = "0";
	int testcase;
	cin >> testcase;
	int x = 1;
	bool isfirst = true;
	for (int i = 0; i < testcase; i++) {
		if (isfirst) {
			cin.ignore();
			isfirst = false;
		}
		string p;
		getline(cin, p);
		string final = "";
		for (int j = 0; j < p.length(); j++) {
			if (j != 0) {
				if (final[final.length()-1] == saver[p[j]][0]) {
					final += ' ';
				}
			}
			final += saver[p[j]];
		}
		cout << "Case #" << x << ": " << final << endl;
		x++;
	}
}