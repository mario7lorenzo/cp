#include <bits/stdc++.h>
using namespace std;

int main() {
	int p;
	cin >> p;
	deque<int> lst;
	for (int i = 0; i < p; i++) {
		int x;
		cin >> x;
		if (lst.size() == 0) {
			lst.push_back(x);
		}
		else {
			if ((lst[lst.size()-1] + x)%2) {
				lst.push_back(x);
			}
			else {
				lst.pop_back();
			}
		}
	}
	cout << lst.size() << endl;
}