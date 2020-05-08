#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,x;
	cin >> n >> x;
	vector<int> z;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		z.push_back(c);
	}
	sort(z.begin(), z.end());
	int counter = 1;
	int curr = z[0];
	for (int i = 1; i < n; i++) {
		if (curr+z[i] > x) {
			break;
		}
		else {
			counter++;
			curr = z[i];
		}
	}
	cout << counter << endl;
}