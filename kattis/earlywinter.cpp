#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, dm;
	cin >> n >> dm;
	bool found = false;
	int k;
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		if (d <= dm) {
			k = i;
			found = true;
		}
	}
	if (found) {
		cout << "It hadn't snowed this early in " << k << " years!" << endl;
	} else {
		cout << "It had never snowed this early!" << endl;
	}
}