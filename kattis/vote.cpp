#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int candidates;
		cin >> candidates;
		int mostvote = -1e9;
		vector<int> winner;
		int totvote = 0;
		for (int j = 1; j <= candidates; j++) {
			int vote;
			cin >> vote;
			totvote += vote;
			if (mostvote < vote) {
				winner.clear();
				winner.push_back(j);
				mostvote = vote;
			}
			else if (mostvote == vote) {
				winner.push_back(j);
			}
		}
		if (winner.size() > 1) {
			cout << "no winner" << endl;
		}
		else if (winner.size() == 1 && (double(mostvote)/double(totvote)) <= 0.5) {
			cout << "minority winner " << winner[0] << endl;
		}
		else if (winner.size() == 1 && (double(mostvote)/double(totvote)) > 0.5) {
			cout << "majority winner " << winner[0] << endl;
		}
	}
}