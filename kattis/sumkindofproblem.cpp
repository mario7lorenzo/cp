#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int no;
		cin >> no;
		int num;
		cin >> num;
		cout << no << ' ' << (num * (num + 1)) / 2 << ' ' << (((num * (num + 1)) / 2)*2) - num << ' ' << (((num * (num + 1)) / 2)*2) << endl;
	}
}