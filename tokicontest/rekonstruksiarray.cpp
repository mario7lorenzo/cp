#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> lst;
	for (int i = 0; i < n; i++) {
		int elem;
		cin >> elem;
		lst.push_back(elem);
	}
	int counter = n%m;
	unordered_map<int, stack<int>> dicti1;
	unordered_map<int, int> dicti2;
	unordered_map<int, int> saver;
	for (int i = 1; i < n+1; i++) {
		dicti1[i%m].push(i);
		dicti2[i%m]++;
		saver[lst[i-1]]++;
	}
	if (dicti2 != saver) {
		cout << -1 << endl;
	}
	else {
		bool isfirst = true;
		for (int i = 0; i < lst.size(); i++) {
			if (isfirst) {
				if (dicti1[lst[i]].size() > 0) {
					cout << dicti1[lst[i]].top();
					dicti1[lst[i]].pop();
					isfirst = false;
				}
			}
			else {
				if (dicti1[lst[i]].size() > 0) {
					cout << ' ' << dicti1[lst[i]].top();
					dicti1[lst[i]].pop();
				}
			}
		}
		cout << endl;
	}
}