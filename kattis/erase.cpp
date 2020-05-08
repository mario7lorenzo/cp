#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool deleter = true;
	string ifirst, isecond;
	cin >> ifirst >> isecond;
	for (int i = 0; i < ifirst.size(); i++) {
		if (n%2 != 0) {
			if (ifirst[i] == isecond[i]) {
				deleter = false;
				break;
			}
		}
		else if (n%2 == 0) {
			if (ifirst[i] != isecond[i]) {
				deleter = false;
				break;
			}
		}
	}
	if (deleter) {
		cout << "Deletion succeeded" << endl;
	}
	else {
		cout << "Deletion failed" << endl;
	}
}