#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> adder(long long x, pair<long long, long long> f) {
	return make_pair((x * f.second + f.first), f.second);
}

pair<long long, long long> reciprocal(pair<long long, long long> x) {
	return make_pair(x.second, x.first);
}

int main() {
	int n;
	cin >> n;
	stack<long long> stk;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		stk.push(x);
	}
	pair<long long, long long> frac = make_pair(1, stk.top());
	stk.pop();
	while (!stk.empty()) {
		frac = adder(stk.top(), frac);
		stk.pop();
		frac = reciprocal(frac);
	}
	cout << frac.second << '/' << frac.first << endl;
}