#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	bool isfirst = true;
	while (cin >> n, n != 0) {
		if (isfirst) {
			isfirst = false;
		}
		else {
			cout << endl;
		}
		cin >> k;
		int tot = k*(n*(n-1)/2);
		if (n == 1) {
			cout << '-' << endl;
		}
		else {
			vector<vector<int>> lst;
			for (int i = 0; i < n; i++) {
				vector<int> temp;
				lst.push_back(temp);
			}
			int a, b;
			string resa, resb;
			for (int i = 0; i < tot; i++) {
				cin >> a >> resa >> b >> resb;
				a--;
				b--;
				// cout << a << ' ' << resa << ' ' << b<< ' ' << resb << endl;
				if (resa != resb) {
					if (resa == "scissors" && resb == "paper") {
						lst[a].push_back(1);
						lst[b].push_back(0);
					}
					if (resa == "paper" && resb == "rock") {
						lst[a].push_back(1);
						lst[b].push_back(0);
					}
					if (resa == "rock" && resb == "scissors") {
						lst[a].push_back(1);
						lst[b].push_back(0);
					}
					if (resa == "paper" && resb == "scissors") {
						lst[a].push_back(0);
						lst[b].push_back(1);
					}
					if (resa == "scissors" && resb == "rock") {
						lst[a].push_back(0);
						lst[b].push_back(1);
					}
					if (resa == "rock" && resb == "paper") {
						lst[a].push_back(0);
						lst[b].push_back(1);
					}
				}			
			}
			for (int i = 0; i < n; i++) {
				if (lst[i].size() == 0) {
					cout << "-" << endl;
				}
				else {
					double prob;
					int win = 0;
					for (int j = 0; j < lst[i].size(); j++) {
						if (lst[i][j]) {
							win++;
						}
					}
					prob = double(win)/double(lst[i].size());
					cout << fixed << setprecision(3) << prob << endl;
				}
			}			
		}
	}
}