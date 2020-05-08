#include <bits/stdc++.h>
using namespace std;

bool cuscom(pair<string,int> x, pair<string,int> y) {
	return x.first < y.first;
}
bool cuscom2(pair<string,int> x, pair<string,int> y) {
	return x.second < y.second;
}
int main() {
	unordered_map<char, pair<int, int>> saver;
	saver['q'] = make_pair(0, 0);
	saver['w'] = make_pair(1, 0);
	saver['e'] = make_pair(2, 0);
	saver['r'] = make_pair(3, 0);
	saver['t'] = make_pair(4, 0);
	saver['y'] = make_pair(5, 0);
	saver['u'] = make_pair(6, 0);
	saver['i'] = make_pair(7, 0);
	saver['o'] = make_pair(8, 0);
	saver['p'] = make_pair(9, 0);
	saver['a'] = make_pair(0, 1);
	saver['s'] = make_pair(1, 1);
	saver['d'] = make_pair(2, 1);
	saver['f'] = make_pair(3, 1);
	saver['g'] = make_pair(4, 1);
	saver['h'] = make_pair(5, 1);
	saver['j'] = make_pair(6, 1);
	saver['k'] = make_pair(7, 1);
	saver['l'] = make_pair(8, 1);
	saver['z'] = make_pair(0, 2);
	saver['x'] = make_pair(1, 2);
	saver['c'] = make_pair(2, 2);
	saver['v'] = make_pair(3, 2);
	saver['b'] = make_pair(4, 2);
	saver['n'] = make_pair(5, 2);
	saver['m'] = make_pair(6, 2);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string ori;
		int tt;
		cin >> ori >> tt;
		vector<pair<string, int>> final;
		for (int j = 0; j < tt; j++) {
			string typo;
			cin >> typo;
			int dist = 0;
			for (int k = 0; k < ori.length(); k++) {
				dist += abs((saver[ori[k]].first - saver[typo[k]].first)) + abs((saver[ori[k]].second - saver[typo[k]].second));
			}
			final.emplace_back(typo, dist);
		}
		sort(final.begin(), final.end(), cuscom);
		sort(final.begin(), final.end(), cuscom2);
		for (int j = 0; j < tt; j++) {
			cout << final[j].first << ' ' << final[j].second << endl;
		}
	}
}