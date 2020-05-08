#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
	float a, n, r, mx;
	cin >> a >> n;
	r = n / (2 * M_PI);
	mx = M_PI * pow(r, 2);
	if (mx >= a) {
		cout << "Diablo is happy!" << endl;
	}
	else {
		cout << "Need more materials!" << endl;
	}
}