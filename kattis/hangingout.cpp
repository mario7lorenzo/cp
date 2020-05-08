#include <bits/stdc++.h>
using namespace std;

int main() {
	int l, x, counter = 0, curr = 0;
	cin >> l >> x;
	while(x--) {
		string comm;
		int c;
		cin >> comm >> c;
		if (comm == "enter") {
			if (curr + c > l) {
				counter++;
			} else {
				curr += c;
			}
		} else {
			curr -= c;
		}
	} 
	cout << counter << endl;
}