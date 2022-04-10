#include<bits/stdc++.h>
using namespace std;


int main() {
	int k;
	cin >> k;

	vector<int> v;

	for (int i = 0; i < k; i++) {
		int elem;
		cin >> elem;
		v.push_back(elem);
	}

	vector<bool> is_visited;

	int passes = 1;
	int prev = v[0];

	for (int i = 1; i < k; i++) {
		if (v[i] < prev) {
			passes += 1;
		}
		prev = v[i];
	}

	cout << passes << endl;
}