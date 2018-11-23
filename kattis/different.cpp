#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b;
	while (cin >> a >> b) {
		long long final = a - b;
		if (final < 0) {
			cout << -final << endl; 
		}
		else {
			cout << final << endl;
		}
	}
}	