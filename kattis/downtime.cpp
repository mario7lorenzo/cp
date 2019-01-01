#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> server;
	vector<int> diff;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		server.push_back(x);
	}
	for (int i = 1; i < n; i++) {
		diff.push_back(server[i]-server[i-1]);
	}
	int maxi = 0, pivot = 0, currt = 0, y = 1;
	for (int i = 0; i < diff.size(); i++) {
		currt += diff[i];
		y++;
		while (currt >= 1000) {
			currt-=diff[pivot];
			pivot++;
			y--;
		}
		maxi = max(maxi, y);
	}
	if (n == 1) {
		cout << 1 << endl;
	}
	else if (maxi % k == 0) {
		cout << maxi/k << endl;
	}
	else if (maxi%k != 0) {
		cout << (maxi/k)+1 << endl;
	}
}