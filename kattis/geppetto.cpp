#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_set<int>> constraint;


vector<unordered_set<int>> possible_subsets(int n) {
	if (n == 0) {
		unordered_set<int> uset;
		vector<unordered_set<int>> vuset;
		vuset.push_back(uset);
		return vuset;
	} else {
		vector<unordered_set<int>> not_used = possible_subsets(n-1);
		vector<unordered_set<int>> used = not_used;
		unordered_set<int> constraints = constraint[n];
		for (auto i: not_used) {
			bool can = true;
			for (auto j: constraints) {
				if (i.find(j) != i.end()) {
					can = false;
					break;
				}
			}
			if (can) {
				unordered_set<int> temp = i;
				temp.insert(n);
				used.push_back(temp);
			}
		}
		return used;
	}
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	while(m--) {
		int a, b;
		cin >> a >> b;
		constraint[a].insert(b);
		constraint[b].insert(a);
	}
	cout << possible_subsets(n).size() << endl;
}