#include <bits/stdc++.h>
using namespace std;

string lowconverter(string x) {
	string final = "";
	for (int i = 0; i < x.length(); i++) {
		int ind = int(x[i]);
		if (ind >= 65 && ind <= 90) {
			ind += 32;
		}
		final += char(ind);
	}
	return final;
}

int main() {
	unordered_set<string> saver;
	string p;
	while (getline(cin, p)) {
		string temp = "";
		bool isfirst = true;
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == ' ') {
				if (isfirst) {
					if (saver.find(lowconverter(temp)) != saver.end()) {
						cout << ".";
					}
					else {
						saver.insert(lowconverter(temp));
						cout << temp;
					}
					isfirst = false;
				}
				else {
					if (saver.find(lowconverter(temp)) != saver.end()) {
						cout << " .";
					}
					else {
						saver.insert(lowconverter(temp));
						cout << ' ' << temp;
					}
				}
				temp = "";
			}
			else {
				temp += p[i];
			}
		}
		if (isfirst) {
			if (saver.find(lowconverter(temp)) != saver.end()) {
				cout << ".";
			}
			else {
				saver.insert(lowconverter(temp));
				cout << temp;
			}
			isfirst = false;
		}
		else {
			if (saver.find(lowconverter(temp)) != saver.end()) {
				cout << " .";
			}
			else {
				saver.insert(lowconverter(temp));
				cout << ' ' << temp;
			}
		}
		cout << endl;
	}
}