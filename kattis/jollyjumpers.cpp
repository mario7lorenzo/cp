#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		unordered_set<int> uset;
		int curr;
		cin >> curr;
		int ori = n;
		n--;
		while (n--) {
			int x;
			cin >> x;
			int diff = abs(x-curr);
			if (diff <= ori-1 && diff >= 1) {
				uset.insert(diff);
			}
			curr = x;
		}
		if (uset.size() == ori-1) {
			cout << "Jolly" << endl;
		} else {
			cout << "Not jolly" << endl;
		}
	}
}