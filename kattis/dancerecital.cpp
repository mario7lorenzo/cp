#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int compare(string a, string b) {
	unordered_set<char> ua, ub;
	for (int i = 0; i < a.length(); i++) {
		ua.insert(a[i]);
	}
	for (int i = 0; i < b.length(); i++) {
		ub.insert(b[i]);
	}
	unordered_set<char>::iterator itr;
	int counter = 0;
	for (itr = ua.begin(); itr != ua.end(); itr++) {
		if (ub.find(*itr) != ub.end()) {
			counter++;
		}
	}
	return counter;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int ori, r;
	cin >> r;
	ori = r;
	vector<string> vs;
	vector<int> vi;
	while (r--) {
		string x;
		cin >> x;
		vs.push_back(x);
	}
	sort(vs.begin(), vs.end());
	int mini = 1e9;
	unordered_map<int, string> hashes;
	vector<vector<int>> edit_distance;
	for (int i = 0; i < ori; i++) {
		vector<int> vt;
		for (int j = 0; j < ori; j++) {
			vt.push_back(0);
		}
		edit_distance.push_back(vt);
		vi.push_back(i);
	}
	for (int i = 0; i < ori; i++) {
		hashes[i] = vs[i];
		vi[i] = i;
	}
	for (int i = 0; i < ori; i++) {
		for (int j = i+1; j < ori; j++) {
			string x = hashes[i];
			string y = hashes[j];
			int dist = compare(x, y);
			edit_distance[i][j] = dist;
			edit_distance[j][i] = dist;
		}
	}
	int counter = 0;
	for (int i = 1; i < ori; i++) {
		counter += edit_distance[vi[i-1]][vi[i]];
	}
	mini = min(mini, counter);
	while (next_permutation(vi.begin(), vi.end())) {
		counter = 0;
		for (int i = 1; i < ori; i++) {
			counter += edit_distance[vi[i-1]][vi[i]];
		}
		mini = min(mini, counter);
	}
	cout << mini << endl;
}