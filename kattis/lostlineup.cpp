#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec;

	for (int i = 0; i < n; i++) {
		vec.push_back(-1);
	}
	vec[0] = 1;

	for (int i = 2; i <= n; i++) {
		int ind;
		cin >> ind;
		vec[ind+1] = i;
	}

	for (int i = 0; i < n; i++) {
		cout << vec[i] << ' ';
	}

	cout << endl;
}