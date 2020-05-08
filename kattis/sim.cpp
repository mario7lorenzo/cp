#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	string dummy;
	getline(cin, dummy);

	for (int i = 0; i < tc; i++) {
		string stream;
		getline(cin, stream);

		deque<deque<char>> dqq;

		bool is_first = true;

		deque<char> dumb;

		dqq.push_back(dumb);

		for (char i : stream) {
			if (i == '<') {
				if (is_first) {
					if (!dqq.front().empty()) {
						dqq.front().pop_back();
					}
				} else {
					if (!dqq.back().empty()) {
						dqq.back().pop_back();
					}
				}
			} else if (i == '[') {
				deque<char> new_dq;
				dqq.push_front(new_dq);
				is_first = true;
			} else if (i == ']') {
				is_first = false;
			} else {
				if (is_first) {
					dqq.front().push_back(i);
				} else {
					dqq.back().push_back(i);
				}
			}
		}

		int sz = dqq.size();

		for (int i = 0; i < sz; i++) {
			deque<char> dq = dqq.front();

			int sz2 = dq.size();

			for (int j = 0; j < sz2; j++) {
				cout << dq.front();
				dq.pop_front();
			}

			dqq.pop_front();
		}

		cout << endl;
	}
}