#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> balloon;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		balloon.push_back(x);
	}
	int curr = -3;
	for (int i = 0; i < balloon.size(); i++) {
		curr = max(balloon[i], curr);
	}
	int arrow = 0;
	while (curr > 0) {
		for (int i = 0; i < balloon.size(); i++) {
			if (curr == balloon[i]) {
				curr--;
				balloon[i] = 0;
			}
		}
		curr = -1e9;
		for (int i = 0; i < balloon.size(); i++) {
			curr = max(balloon[i], curr);
		}
		arrow++;
	}
	cout << arrow << endl;
}