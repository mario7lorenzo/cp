#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int cal;
		cin >> cal;
		if (cal%400 != 0) {
			cout << (cal/400)+1 << endl;
		}
		else {
			cout << cal/400 << endl;
		}
	}
}