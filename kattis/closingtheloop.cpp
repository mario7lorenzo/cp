#include <bits/stdc++.h>
using namespace std;

pair<bool, int> parser(string x) {
	int len = x.length();
	if (x[len-1] == 'B') {
		return make_pair(false, stoi(x.substr(0, len-1)));
	} else {
		return make_pair(true, stoi(x.substr(0, len-1)));
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int s;
		priority_queue<int> r, b;
		cin >> s;
		for (int i = 0; i < s; i = i + 1) {
			string c;
			cin >> c;
			pair<bool, int> res = parser(c);
			if (res.first) {
				r.push(res.second);
			} else {
				b.push(res.second);
			}
		}
		int acc = 0;
		bool isfirst = true;
		while (!r.empty() && !b.empty()) {
			acc += r.top() + b.top() - 1;
			r.pop();
			b.pop();
			if (isfirst) {
				isfirst = false;
			} else {
				acc--;
			}
		}
		cout << "Case #" << i << ": "; 
		if (acc == 0) {
			cout << acc << endl;
		} else {
			cout << acc-1 << endl;
		}
	}
}