#include <bits/stdc++.h>
using namespace std;

int main() {
	int rot;
	while (cin >> rot, rot != 0) {
		string wr;
		cin >> wr;
		string final = "";
		for (int i = 0; i < wr.length(); i++) {
			int temp;
			if (wr[i] == '_') {
				temp = 91 + rot;
			}
			else if (wr[i] == '.') {
				temp = 92 + rot;
			}
			else {
				temp = wr[i] + rot;
			}
			if (temp > 92) {
				temp -= 28;
			}
			if (temp == 92) {
				final += '.';
			}
			else if (temp == 91) {
				final += '_';
			}
			else {
				final += char(temp);
			}
		}
		for (int i = final.length(); i > 0; i--) {
			cout << final[i-1];
		}
		cout << endl;
	}
}