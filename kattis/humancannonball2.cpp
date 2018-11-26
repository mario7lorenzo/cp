#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		float vo, o, x1, h1, h2;
		cin >> vo >> o >> x1 >> h1 >> h2;
		float t;
		t = x1/(vo*cos((o/(360))*2*M_PI));
		float hf = (vo*t*sin((o/(360))*2*M_PI)) - (0.5*9.81*t*t);
		if (h1+1 < hf && hf < h2-1) {
			cout << "Safe" << endl;
		}
		else {
			cout << "Not Safe" << endl;
		}
	}
}