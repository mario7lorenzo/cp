#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;

	int tot = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int no;
		cin >> no;
		if (no < 0) {
			tot += -no;
		}
	}

	cout << tot << endl;
}