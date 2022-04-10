#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	string summer;
	cin >> summer;
	int n = summer.length();

	ll total = 0;
	for (int i = 0; i < n-1; i++) {
		unordered_set<char> is_visited;

		for (int j = i+1; j < n; j++) {
			if (summer[i] == summer[j]) {
				break;
			}

			if (is_visited.find(summer[j]) == is_visited.end()) {
				total++;
			}

			is_visited.insert(summer[j]);
		}
	}

	cout << total << endl;
}