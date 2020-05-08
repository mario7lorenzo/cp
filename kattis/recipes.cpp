#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	int recipes = 1;
	for (int i = 0; i < testcase; i++) {
		int r, p, d;
		cin >> r >> p >> d;
		double scalefactor = double(d) / double(p);
		vector<pair<string, pair<double, double>>> saver;
		double scaleweight;
		for (int i = 0; i < r; i++) {
			string name;
			double w, per;
			cin >> name >> w >> per;
			if (per == 100.0) {
				scaleweight = w;
			}
			pair<double, double> temp = make_pair(w, per);
			saver.emplace_back(name, temp);
		}
		cout << "Recipe # " << recipes << endl;
		for (int j = 0; j < saver.size(); j++) {
			double val = scalefactor * scaleweight * (saver[j].second.second/100.0);
			cout << saver[j].first << ' ';
			cout << fixed << setprecision(1) << val << endl;
		}
		cout << "----------------------------------------" << endl;
		recipes++;
	}
}