#include <bits/stdc++.h>
using namespace std;

deque<int> d1, d2;

int size1 = 0, size2 = 0;

void adjust() {
	if (size1 - size2 > 1) {
		int temp = d1.back();
		d1.pop_back();
		d2.push_front(temp);
		size1--;
		size2++;
	} else if (size2 - size1 > 0) {
		int temp = d2.front();
		d2.pop_front();
		d1.push_back(temp);
		size1++;
		size2--;
	}
}

void act(string op, int x) {
	if (op == "push_front") {
		d1.push_front(x);
		size1++;
	} else if (op == "push_back") {
		d2.push_back(x);
		size2++;
	} else if (op == "push_middle") {
		d1.push_back(x);
		size1++;
	} else if (op == "get") {
		if (x < size1) {
			cout << d1[x] << endl;
		} else {
			cout << d2[x-size1] << endl;
		}
	}
	adjust();
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int op;
	cin >> op;
	while (op--) {
		string action;
		int c;
		cin >> action >> c;
		act(action, c);
	}
}