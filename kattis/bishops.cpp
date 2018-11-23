#include <bits/stdc++.h>
using namespace std;

int main() {
	string p;
	while (getline(cin, p)) {
		if (p == "1") {
			cout << 1 << endl;
		}
		else { 
			cout << 2 * (stoi(p) - 1) << endl;
		}
	}
}