#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	unordered_map<int, int> ctox;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		ctox[i] = x;
	}
	for (int i = 0; i < q; i++) {
		int req;
		cin >> req;
		if (req == 1) {
			int c, x;
			cin >> c >> x;
			ctox[c] = x;
		} else {
			int a, b;
			cin >> a >> b;
			cout << abs(ctox[a]-ctox[b]) << endl;
		}
	}
}