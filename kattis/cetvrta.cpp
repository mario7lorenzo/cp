#include <bits/stdc++.h>
using namespace std;
#include <cmath>

int main() {
	int p, g, h;
	vector<int> xlst;
	vector<int> ylst;
	int counter = 0;
	for (int i = 0; i < 6; i++) {
		cin >> p;
		if ((counter + 1) % 2) {
			xlst.push_back(p);
		}
		else {
			ylst.push_back(p);
		}
		counter += 1;
	}
	sort(ylst.begin(), ylst.end());
	if (xlst[1] == xlst[0]) {
		g = xlst[2];
	}
	else {
		g = xlst[0];
	}
	if (ylst[1] == ylst[0]) {
		h = ylst[2];
	}
	else {
		h = ylst[0];
	}
	cout << g << " " << h << endl;	
}