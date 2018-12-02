#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int k, bs;
		cin >> k >> bs;
		int num;
		cin>> num;
		int final = 0;
		while (num > 0) {
			final += pow((num%bs), 2);
			num /= bs;
		}
		cout << k << ' ' << final << endl;
	}
}