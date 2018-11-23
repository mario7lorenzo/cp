#include <bits/stdc++.h>
using namespace std;

int main() {
	int total, counter;
	cin >> total;
	counter = 0;
	for (int i = 0; i < total; i++) {
		int p;
		cin >> p;
		if (p < 0) {
			counter += 1;
		}
	}
	cout << counter << endl;
}