#include <bits/stdc++.h>
using namespace std;
int fact(int x) {
	if (x==0 || x == 1) {
		return 1;
	}
	else {
		return x * fact(x-1);
	}
}

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int x;
		cin >> x;
		long long fc = fact(x);
		string fct = to_string(fc);
		cout << fct[fct.length()-1] << endl;
	}
}