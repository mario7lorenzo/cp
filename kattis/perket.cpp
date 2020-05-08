#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	unordered_map<int, pair<int, int>> saver;
	for (int i= 0; i < n; i++) {
		int s, b;
		cin >> s >> b;
		saver[i] = make_pair(s, b);
	}
	int mini = 1e9+2;
	for (int i = 1; i < pow(2, n); i++) {
		bitset<10> bs(i);
		int stot = 1, btot = 0;
		for (int i = 0; i < 10; i++) {
			if (bs[i]) {
				stot *= saver[i].first;
				btot += saver[i].second;
			}
		}
		mini = min(mini, abs(stot-btot));
	}
	cout << mini << endl;
}
