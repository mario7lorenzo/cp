#include <bits/stdc++.h>
using namespace std;

int main() {
	long long sz;
	cin >> sz;
	for (long long i = 0; i < sz; i++) {
		long long x;
		cin >> x;
		long long saver;
		long long counter = 1;
		if (i == 0) {
			saver = x;
			cout << x << ' '; 
		}
		else {
			if (saver < x) {
				saver = x;
				cout << x << ' ';
				counter++;
			} 
		}
	}
	cout << endl;
}