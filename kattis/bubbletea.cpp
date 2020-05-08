#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, mini = 1e9;
	long long money;
	vector<int> tea, topping;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		tea.push_back(temp);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		topping.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int cat;
			cin >> cat;
			mini = min(mini, (tea[i] + topping[cat-1]));
		}
	}
	cin >> money;
	if ((money/mini) < 1) {
		cout << 0 << endl;
	}
	else {
		cout << (money/mini)-1 << endl;
	}
}