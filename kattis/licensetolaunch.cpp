#include <bits/stdc++.h>
using namespace std;

int main() {
	int days;
	cin >> days;
	int mini = 1e9;
	int ke;
	for (int i = 0; i < days; i++) {
		int junk;
		cin >> junk;
		if (mini > junk) {
			ke = i;
			mini = junk;
		}
	}
	cout << ke << endl;
}