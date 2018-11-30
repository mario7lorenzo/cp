#include <bits/stdc++.h>
using namespace std;

bool verifier[200100];
bool isfirst = true;
int neighbor[200100];
int total[200100];
map<int, vector<int>> al;

void decider(int x) {
	int counter = 0;
	for (int i = 0; i < al[x].size(); i++) {
		if (verifier[al[x][i]]) {
			counter++;
		}
	}
	if (2*counter >= al[x].size()) {
		verifier[x] = true;
	}
}

int main() {
	int c, p, x, l;
	cin >> c >> p >> x >> l;
	for (int i = 0; i < c+2; i++) {
		verifier[i] = false;
		neighbor[i] = 0;
		total[i] = 0;
	}
	for (int i = 0; i < p; i++) {
		int a, y;
		cin >> a >> y;
		neighbor[a]++;
		neighbor[y]++;
		total[a]++;
		total[y]++;
		al[a].push_back(y);
		al[y].push_back(a);
	}
	verifier[l] = true;
	queue<int> q;
	for (int i = 0; i < al[l].size(); i++) {
		q.push(al[l][i]);
		neighbor[al[l][i]]--;
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (!verifier[u]) {
			if (neighbor[al[u]] <= al[u].size()/2) {
				verifier[u]
			}
		}
		
	}
	if (verifier[x]) {
		cout << "leave" << endl;
	}
	else {
		cout << "stay" << endl;
	}
}