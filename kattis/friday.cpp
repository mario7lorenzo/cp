#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int totd, m;
		cin >> totd >> m;
		int init = 0;
		vector<int> lst;
		vector<int> totdays;
		lst.push_back(init);
		for (int i = 0; i < m; i++) {
			int days;
			cin >> days;
			init += days;
			totdays.push_back(days);
			lst.push_back(init%7);
		}
		int counter = 0;
		for (int i = 0; i < lst.size(); i++) {
			if (lst[i] == 0 && totdays[i] >= 13) {
				counter++;
			}
		}
		cout << counter << endl;
	}
} 