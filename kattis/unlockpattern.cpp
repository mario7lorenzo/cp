#include <bits/stdc++.h>
using namespace std;

float calc(pair<int, int> a, pair<int, int> b) {
	return sqrt(float(pow(a.first-b.first, 2)+pow(a.second-b.second, 2)));
}

int main() {
	map<int, pair<int, int> > umap;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int x;
			cin >> x;
			umap[x] = make_pair(i, j);
		}
	}
	float summ = 0.0;
	for (int i = 2; i <= 9; i++) {
		summ += calc(umap[i], umap[i-1]);
	}
	cout << std::setprecision(9) << summ << endl;
}