#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		float p;
		int b;
		cin >> b >> p;
		float aver = (60 * b)/p;
		float mini = aver - aver/b;
		float maxi = aver + aver/b;
		cout << fixed << setprecision(4) << mini << ' ' << aver << ' ' << maxi << endl;
	}
}