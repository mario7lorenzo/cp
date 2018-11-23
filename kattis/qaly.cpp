#include <bits/stdc++.h>
using namespace std;

int main() {
	int acc;
	cin >> acc;
	float counter = 0.0;
	for (int i = 0; i < acc; i++) {
		float a, b;
		cin >> a >> b;
		counter += (a * b);
	}
	cout << fixed << setprecision(3) << counter << endl;
}