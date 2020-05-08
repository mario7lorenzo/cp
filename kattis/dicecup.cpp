#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<int, int> saver;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			saver[i+j]++;
		}
	}
	map<int, int>::iterator i;
	int maxi = -1;
	for (i = saver.begin(); i != saver.end(); i++) {
		maxi = max(maxi, i->second);
	}
	for (i = saver.begin(); i != saver.end(); i++) {
		if (i->second == maxi) {
			cout << i->first << endl;
		}
	}
}