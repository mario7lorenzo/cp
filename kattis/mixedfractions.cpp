#include <bits/stdc++.h>
using namespace std;

int main() {
	long long numer, denom;
	while (cin >> numer >> denom , numer != 0 && denom != 0) {
		long long whole = numer / denom;
		long long remain = numer%denom;
		cout << whole << ' ' << remain << " / " << denom << endl;
	}
}