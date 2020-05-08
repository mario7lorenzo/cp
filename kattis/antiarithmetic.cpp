#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	string num;
	while (cin >> num, num != "0") {
		string temp = "";
		int n;
		for (auto i : num) {
			if (i == ':') {
				n = stoi(temp);
			} else {
				temp += i;
			}
		}
		bool anti = true;
		vector<int> vi;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			vi.push_back(x);
		}
		unordered_set<int> bag;
		for (int i = 0; i < n; i++) {
			int a = vi[i];
			for (int j = i+1; j < n; j++) {
				int b = vi[j];
				int diff = b-a;
				int c = b+diff;
				if (c >= 0 && c < n && bag.find(c) == bag.end()) {
					cout << a << ' ' << b << endl;
					anti = false;
					break;
				}
			}
			if (!anti) {
				break;
			}
		}
		if (anti) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
}