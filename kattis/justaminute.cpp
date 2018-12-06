#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	double act = 0, est = 0;
	for (int i = 0; i < n; i++) {
		double a, e;
		cin >> e >> a;
		act += a;
		est += e;
	}
	est *= 60;
	if (act <= est) {
		cout << "measurement error" << endl;
	}
	else {
		cout << fixed << setprecision(10) << act/est << endl;
	}
}