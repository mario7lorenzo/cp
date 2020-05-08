#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> saver;
	for (int i = 0; i < 4; i++) {
		int x;
		cin >> x;
		saver.push_back(x);
	}
	sort(saver.begin(), saver.end());
	cout << saver[0] * saver[2] << endl;
}