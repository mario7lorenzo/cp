#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main () {
	int counter, length, width;
	double diagonal;
	cin >> counter >> length >> width;
	diagonal = sqrt(pow(length, 2) + pow(width, 2));
	for (int i = 0; i < counter; i++) {
		int p;
		cin >> p;
		if (p <= diagonal) {
			cout << "DA" << endl;
		}
		else {
			cout << "NE" << endl;
		}
	}
}