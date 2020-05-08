#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, t, m;
		cin >> n >> t >> m;
		queue<pair<int, int>> left, right;
		bool pos = true;
		for (int i = 0; i < m; i++) {
			int time;
			string posi;
			cin >> time >> posi;
			if (posi == "left") {
				left.push(make_pair(time, i));
			} else {
				right.push(make_pair(time, i));
			}
		}
		unordered_map<int, int> id;
		int currtime = 0;
		while (!left.empty() || !right.empty()) {
			if (right.empty()) {
				pair<int, int> qleft = left.front();
				if (pos) {
					int load = 0;
					stack<int> stk;
					currtime = max(currtime, qleft.first);
					while (!left.empty() && left.front().first <= currtime && load < n) {
						load++;
						stk.push(left.front().second);
						left.pop();
					}
					currtime += t;
					pos = !pos;
					while (!stk.empty()) {
						id[stk.top()] = currtime;
						stk.pop();
					}
				} else {
					currtime = max(currtime, qleft.first);
					currtime += t;
					pos = !pos;
				}
			}
			else if (left.empty()) {
				pair<int, int> qright = right.front();
				if (!pos) {
					int load = 0;
					stack<int> stk;
					currtime = max(currtime, qright.first);
					while (!right.empty() && right.front().first <= currtime && load < n) {
						load++;
						stk.push(right.front().second);
						right.pop();
					}
					currtime += t;
					pos = !pos;
					while (!stk.empty()) {
						id[stk.top()] = currtime;
						stk.pop();
					}
				} else {
					currtime = max(currtime, qright.first);
					currtime += t;
					pos = !pos;
				}
			} else {
				pair<int, int> qleft = left.front();
				pair<int, int> qright = right.front();
				if (pos) {
					if (qleft.first <= currtime || qleft.first <= qright.first) {
						int load = 0;
						stack<int> stk;
						currtime = max(currtime, qleft.first);
						while (!left.empty() && left.front().first <= currtime && load < n) {
							load++;
							stk.push(left.front().second);
							left.pop();
						}
						currtime += t;
						pos = !pos;
						while (!stk.empty()) {
							id[stk.top()] = currtime;
							stk.pop();
						}
					} else {
						currtime = max(currtime, qright.first);
						currtime += t;
						int load = 0;
						stack<int> stk;
						while (!right.empty() && right.front().first <= currtime && load < n) {
							load++;
							stk.push(right.front().second);
							right.pop();
						}
						currtime += t;
						while (!stk.empty()) {
							id[stk.top()] = currtime;
							stk.pop();
						}
					}
				} else {
					if (qright.first <= currtime || qright.first <= qleft.first) {
						int load = 0;
						stack<int> stk;
						currtime = max(currtime, qright.first);
						while (!right.empty() && right.front().first <= currtime && load < n) {
							load++;
							stk.push(right.front().second);
							right.pop();
						}
						currtime += t;
						pos = !pos;
						while (!stk.empty()) {
							id[stk.top()] = currtime;
							stk.pop();
						}
					} else {
						currtime = max(currtime, qleft.first);
						currtime += t;
						int load = 0;
						stack<int> stk;
						while (!left.empty() && left.front().first <= currtime && load < n) {
							load++;
							stk.push(left.front().second);
							left.pop();
						}
						currtime += t;
						while (!stk.empty()) {
							id[stk.top()] = currtime;
							stk.pop();
						}
					}
				}
			}
		}
		for (int i = 0; i < m; i++) {
			cout << id[i] << endl;
		}
		cout << endl;
	}
}