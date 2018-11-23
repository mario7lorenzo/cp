#include <bits/stdc++.h>
using namespace std;

int main() {
	int itr;
	int adder = 1;
	cin >> itr;
	long long base = 2;
	while (itr > 0) {
		base *= 2;
		base--;
		itr--;
	}
	cout << base * base << endl;
}