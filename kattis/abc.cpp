#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> lst;
	lst.push_back(a);
	lst.push_back(b);
	lst.push_back(c);
	sort(lst.begin(), lst.end());
	string op;
	cin >> op;
	bool is_first = true;
	for (int i = 0; i < op.length(); i++) {
		if (is_first) {
			is_first = false;
		}
		else {
			cout << ' ';
		}
		if (op[i] == 'A') {
			cout << lst[0];
		}
		else if (op[i] == 'B') {
			cout << lst[1];
		}
		else {
			cout << lst[2];
		}
	}
	cout << endl;
}