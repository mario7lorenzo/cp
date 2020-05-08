#include <bits/stdc++.h>
using namespace std;

int main() {
	string x;
	cin >> x;
	bool can = next_permutation(x.begin(), x.end());
	if (!can) {
		cout << 0 << endl;
	}
	else {
		cout << x << endl;
	}
} 