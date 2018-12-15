#include <bits/stdc++.h>
using namespace std;

int main() {
	int events;
	cin >> events;
	unordered_set<int> lst;
	for (int i = 0; i < events; i++) {
		int s, t;
		cin >> s >> t;
		for (int j = s; j <= t; j++) {
			lst.insert(j);
		}
	}
	cout << lst.size() << endl;
}