#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int tb = 0;
	int lr = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			char c;
			cin >> c;

			if (c == '0') {
				tb++;
			}
		}

		for (int j = 0; j < 2; j++) {
			char c;
			cin >> c;

			if (c == '0') {
				lr++;
			}
		}		
	}

	int totswords = min(tb/2, lr/2);
	int used = totswords * 2;

	cout << totswords << ' ' << tb - used << ' ' << lr - used << endl;
}