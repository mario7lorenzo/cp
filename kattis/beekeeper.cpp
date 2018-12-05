#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n, n != 0) {
		int maxpair = 0;
		string curr = "";
		for (int i = 0; i < n; i++) {
			int now = 0;
			string p;
			cin >> p;
			for (int j = 1; j < p.length(); j++) {
				if (p[j-1] == p[j]) {
					if (p[j] == 'a' || p[j] == 'e' || p[j] == 'i' || p[j] == 'o' || p[j] == 'u' || p[j] == 'y') {
						now++;
					}
				}
			}
			if (maxpair <= now) {
				curr = p;
				maxpair = now;
			}
		}
		cout << curr << endl;
	}
}