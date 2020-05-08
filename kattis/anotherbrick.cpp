#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	int currh = 1;
	int currw = 0;
	int counter = 0;
	bool can = true;
	while (currh <= h) {
		if (counter == n) {
			can = false;
			break;
		}
		int br;
		cin >> br;
		counter++;
		if (currw + br > w) {
			can = false;
			break;
		}
		currw += br;
		if (currw == w) {
			currh++;
			currw = 0;
		}
	}
	if (can) cout << "YES" << endl;
	else cout << "NO" << endl;
}