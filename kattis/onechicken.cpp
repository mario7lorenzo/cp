#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a < b) {
		if (b-a == 1) {
			cout << "Dr. Chaz will have " << b-a << " piece of chicken left over!" << endl;
		}
		else {
			cout << "Dr. Chaz will have " << b-a << " pieces of chicken left over!" << endl;
		}
	}
	else {
		if (a-b == 1) {
			cout << "Dr. Chaz needs " << a-b << " more piece of chicken!" << endl;
		}
		else {
			cout << "Dr. Chaz needs " << a-b << " more pieces of chicken!" << endl;
		}
	}
}