#include <bits/stdc++.h>
using namespace std;

int main() {
	int comm;
	while (cin >> comm) {
		// cout << "ini comm " << comm << endl;
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		vector<int> ori;
		vector<int> ss;
		vector<int> qs;
		vector<int> pqs;
		bool can = true;
		for (int i = 0; i < comm; i++) {
			int op, num;
			cin >> op >> num;
			if (op == 1) {
				s.push(num);
				q.push(num);
				pq.push(num);
			}
			else if (op == 2) {
				if (s.size() == 0) {
					can = false;
					ori.push_back(num);
				}
				else {
					ori.push_back(num);
					ss.push_back(s.top());
					s.pop();
					qs.push_back(q.front());
					q.pop();
					pqs.push_back(pq.top());
					pq.pop();			
				}
			}
		}
		int sim = 0;
		if (ori == ss) {
			sim++;
		}
		if (ori == qs) {
			sim++;
		}
		if (ori == pqs) {
			sim++;
		}
		if (sim == 0 || !can) {
			cout << "impossible" << endl;
		}
		else if (sim > 1) {
			cout << "not sure" << endl;
		}
		else if (sim == 1) {
			if (ori == ss) {
				cout << "stack" << endl;
			}
			else if (ori == qs) {
				cout << "queue" << endl;
			}
			else if (ori == pqs) {
				cout << "priority queue" << endl;
			}
		}
	}
}