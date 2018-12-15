#include <bits/stdc++.h>
using namespace std;

int main() {
	int w, a = 0, n;
	cin >> w >> n;
	for (int i = 0; i < n; i++) {
		int panjang, lebar;
		cin >> panjang >> lebar;
		a += (panjang * lebar);
	}
	cout << a/w << endl;
}