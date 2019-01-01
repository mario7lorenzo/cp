#include <bits/stdc++.h>
using namespace std;

string binconv(int x) {
	string bin = "";
	while (x > 0) {
		bin += to_string(x%2);
		x /= 2;
	}
	reverse(bin.begin(), bin.end());
	while (bin.length() < 7) {
		bin = '0' + bin;
	}
	return bin;
}

int main() {
	string p;
	while (getline(cin, p)) {
		string longbin = "";
		for (int i = 0; i < p.length(); i++) {
			int ascii = int(p[i]);
			longbin += binconv(ascii);
		}
		// release means true, clicked means false
		bool left = true, right = true;
		for (int i = 0; i < longbin.length(); i++) {
			if (longbin[i] == '0') {
				right = !right;
			}
			else {
				left = !left;
			}
		}
		if (left && right) {
			cout << "free" << endl;
		}
		else {
			cout << "trapped" << endl;
		}
	}
}