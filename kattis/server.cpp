#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	int counter = 0;
	int timer = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (timer + p > t) {
			break;
		}
		else {
			timer += p;
			counter += 1;
		}
	}
	cout << counter << endl;
}
