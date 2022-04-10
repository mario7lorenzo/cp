#include<bits/stdc++.h>
using namespace std;

int main() {
	int b, d, c, l;
	cin >> b >> d >> c >> l;

	int one = 0;

	vector<pair<int, pair<int, int>>> result;

	while (one*b <= l) {
		int two = 0;
		int left = l - (one*b);
		while (two*d <= left) {
			int final_left = left - (two*d);

			if (final_left%c == 0) {
				result.push_back(make_pair(one, make_pair(two, final_left/c)));
			}

			two++;
		}

		one++;
	}

	if (!result.size()) {
		cout << "impossible" << endl;
		return 0;
	}

	for (pair<int, pair<int, int>> p : result) {
		cout << p.first << ' ' << p.second.first << ' ' << p.second.second << endl;
	}
}