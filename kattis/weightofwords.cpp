#include <bits/stdc++.h>
using namespace std;

int main() {
	int l, w;
	cin >> l >> w;
	unordered_map<int, char> lst;
	vector<int> saver;
	lst[1] = 'a';
	lst[2] = 'b';
	lst[3] = 'c';
	lst[4] = 'd';
	lst[5] = 'e';
	lst[6] = 'f';
	lst[7] = 'g';
	lst[8] = 'h';
	lst[9] = 'i';
	lst[10] = 'j';
	lst[11] = 'k';
	lst[12] = 'l';
	lst[13] = 'm';
	lst[14] = 'n';
	lst[15] = 'o';
	lst[16] = 'p';
	lst[17] = 'q';
	lst[18] = 'r';
	lst[19] = 's';
	lst[20] = 't';
	lst[21] = 'u';
	lst[22] = 'v';
	lst[23] = 'w';
	lst[24] = 'x';
	lst[25] = 'y';
	lst[26] = 'z';
	if ((double(w)/double(l) > 26) || (double(w)/double(l) < 1)) {
		cout << "impossible" << endl;
	}
	else {
		int weightper = w/l;
		int rem = w%l;
		for (int i = 0; i < l; i++) {
			if (rem > 0) {
				int inc = min(rem, 26-weightper);
				rem -= inc;
				cout << lst[weightper+inc];
			}
			else {
				cout << lst[weightper];
			}
		}
		cout << endl;
	}
}