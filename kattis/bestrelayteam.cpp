#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	double best = 1e9;
	vector<pair<double, string>> frst, other;
	unordered_map<string, pair<double, double>> svr;
	while (n--) {
		string nm;
		double fleg, oleg;
		cin >> nm >> fleg >> oleg;
		frst.emplace_back(fleg, nm);
		other.emplace_back(oleg, nm);
		svr[nm] = make_pair(fleg, oleg);
	}
	sort(frst.begin(), frst.end());
	sort(other.begin(), other.end());
	pair<pair<string, string>, pair<string, string>> lst;
	for (int i = 0; i < frst.size(); i++) {
		string fname = frst[i].second;
		double fdur = frst[i].first;
		int piv1 = 0, piv2 = 1, piv3 = 2;
		if (other[piv1].second == fname) {
			piv1 = 3;
		}
		else if (other[piv2].second == fname) {
			piv2 = 3;
		}
		else if (other[piv3].second == fname) {
			piv3 = 3;
		}
		double tot = fdur + other[piv1].first + other[piv2].first + other[piv3].first;
		if (tot < best) {
			best = tot;
			lst = make_pair(make_pair(fname, other[piv1].second), make_pair(other[piv2].second, other[piv3].second));
		}
	}
	cout << fixed << setprecision(9) << best << endl;
	cout << lst.first.first << endl;
	cout << lst.first.second << endl;
	cout << lst.second.first << endl;
	cout << lst.second.second << endl;
}