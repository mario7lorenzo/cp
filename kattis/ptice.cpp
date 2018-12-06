#include <bits/stdc++.h>
using namespace std;

int main() {
	int prob;
	cin >> prob;
	vector<char> a, b, g;
	a.push_back('A');
	a.push_back('B');
	a.push_back('C');
	b.push_back('B');
	b.push_back('A');
	b.push_back('B');
	b.push_back('C');
	g.push_back('C');
	g.push_back('C');
	g.push_back('A');
	g.push_back('A');
	g.push_back('B');
	g.push_back('B');
	int adrian = 0, bruno = 0, goran = 0;
	for (int i = 0; i < prob; i++) {
		char ans;
		cin >> ans;
		if (a[i%a.size()] == ans) {
			adrian++;
		}
		if (b[i%b.size()] == ans) {
			bruno++;
		}
		if (g[i%g.size()] == ans) {
			goran++;
		}
	}
	int maxi = -1;
	maxi = max(max(adrian, bruno), goran);
	cout << maxi << endl;
	if (maxi == adrian) {
		cout << "Adrian" << endl;
	}
	if (maxi == bruno) {
		cout << "Bruno" << endl;
	}
	if (maxi == goran) {
		cout << "Goran" << endl;
	}
}