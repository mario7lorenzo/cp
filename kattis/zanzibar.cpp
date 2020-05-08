#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int curr;
		cin >> curr;
		int temp;
		int tot = 0;
		while (cin >> temp, temp != 0) {
			if (2*curr < temp) {
				tot += temp-(2*curr);
			} 
			curr = temp;
		}
		cout << tot << endl;
	}
}