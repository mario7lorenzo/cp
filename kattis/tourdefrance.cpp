#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main() {
	int f, b;
	cin >> f;

	while (f) {
		cin >> b;
		vector<double> fs, bs;

		for (int i = 0; i < f; i++) {
			double elem;
			cin >> elem;
			fs.push_back(elem);
		}

		for (int i = 0; i < b; i++) {
			double elem;
			cin >> elem;
			bs.push_back(elem);
		}

		vector<double> ratios;

		for (int i = 0; i < b; i++) {
			for (int j = 0; j < f; j++) {
				ratios.push_back(bs[i]/fs[j]);
			}
		}

		sort(ratios.begin(), ratios.end());

		double maxi = ratios[1]/ratios[0];

		for (int i = 1; i < ratios.size()-1; i++) {
			double ratio = ratios[i+1]/ratios[i];
			maxi = max(maxi, ratio);
		}

		printf("%.2f\n", maxi);
		cin >> f;
	} 
}