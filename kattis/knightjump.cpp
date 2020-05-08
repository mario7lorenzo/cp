#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<char>> vvc;
queue<pair<int, pair<int, int>>> pq;


bool is_valid(int y, int x) {
	return y >= 0 && x >= 0 && y < n && x < n && vvc[y][x] != '#' && vvc[y][x] != 'x';
}

void pusher(int y,int c,int w) {
	pq.push(make_pair(w+1, make_pair(y+2, c+1)));
	pq.push(make_pair(w+1, make_pair(y+2, c-1)));
	pq.push(make_pair(w+1, make_pair(y-2, c+1)));
	pq.push(make_pair(w+1, make_pair(y-2, c-1)));
	pq.push(make_pair(w+1, make_pair(y+1, c+2)));
	pq.push(make_pair(w+1, make_pair(y+1, c-2)));
	pq.push(make_pair(w+1, make_pair(y-1, c+2)));
	pq.push(make_pair(w+1, make_pair(y-1, c-2)));
}

int main() {
	cin >> n;
	bool found = false;
	int y, x;
	int res;
	for (int i = 0; i < n; i++) {
		vector<char> temp;
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == 'K') {
				y = i;
				x = j;
			}
			temp.push_back(c);
		}
		vvc.push_back(temp);
	}
	pq.push(make_pair(0, make_pair(y, x)));
	while (!pq.empty()) {
		pair<int, pair<int, int>> thing = pq.front();
		pq.pop();
		int k = thing.second.first, l = thing.second.second;
		if (k == 0 && l == 0) {
			found = true;
			res = thing.first; 
			break;
		} else if (is_valid(k, l)) {
			pusher(k, l, thing.first);
			vvc[k][l] = 'x';
		}
	}
	if (found) {
		cout << res << endl;
	} else {
		cout << -1 << endl;
	}
}