#include <bits/stdc++.h>
using namespace std;

int r, c, currstar;

string helper(string x) {
	int counter = 0;
	for (auto i : x) {
		if (i == '*') {
			counter++;
		}
	}
	int len = x.length();
	string final = "";
	for (int i = 0; i < len; i++) {
		if (i == currstar && counter > 0) {
			final += '*';
			currstar++;
			counter--;
		} else {
			final += '.';
		}
	}
	reverse(final.begin(), final.end());
	return final;
}

int main() {
	string x;
	string curr;
	bool isfirst = true;
	while (getline(cin, x)) {
		vector<string> vs;
		vs.push_back(x);
		while (getline(cin, x)) {
			if (x == "") {
				break;
			}
			vs.push_back(x);
		}
		r = vs.size();
		c = vs[0].length();
		currstar = 0;
		int counter = 0;
		for (auto i : vs) {
			string res = helper(i);
			cout << res << endl;
		}
		cout << endl;
	}
}