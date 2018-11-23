#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> temp;
map<int, set<int>> al;
bool notweak[25];

bool helper(int x) {
	for (int i = 1; i < temp[x].size(); i++) {
		int node = temp[x][i];
		for (int j = 1; j < temp[node].size(); j++) {
			if (al[x].find(temp[node][j]) != al[x].end()) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n;
	while(cin >> n, n != -1) {
		memset(notweak, false, 25);
		for (int i = 0; i < n + 1; i++) {
			vector<int> otto;
			otto.push_back(-1);
			temp.push_back(otto);
			al[i].insert(-1);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int nodes;
				cin >> nodes;
				if (nodes == 1) {
					al[i].insert(j);
					temp[i].push_back(j);
				}
			}
		}
		for (int i = 0; i < al.size(); i++) {
			notweak[i] = helper(i);
		}
		bool isfirst = true;
		for (int i = 0; i < n; i++) {
			if (notweak[i] == false) {
				if (isfirst) {
					isfirst = false;
					cout << i;
				}
				else {
					cout << ' ' << i;
				}
			}
		}
		temp.clear();
		al.clear();
		cout << endl;
	}
}