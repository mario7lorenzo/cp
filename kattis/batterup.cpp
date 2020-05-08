#include <bits/stdc++.h>
using namespace std;

int main() {
	int total;
	cin >> total;
	int counter = 0;
	int totals = 0;
	for (int i = 0; i < total; i++) {
		int p;
		cin >> p;
		if (p == -1) {
			continue;
		}
		else {
			counter += 1;
			totals += p;
		}
	}
	double avg = double(totals) / counter;
	cout << avg << endl;
}	