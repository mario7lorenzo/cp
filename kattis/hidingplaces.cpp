#include <bits/stdc++.h>
using namespace std;

#define white 10
#define black -10
#define inf 1e9
typedef pair<int, int> ii;


unordered_set<int> saver;
vector<string> final;
int dist[200];
int bfs_num[200];
int p[200];
bool grid[12][12];
map<int, vector<pair<int, int>>> al;
unordered_map<char, int> alphanum;
unordered_map<int, char> numalpha;
unordered_map<int, int> pseudo;

bool cuscom2(string x, string y) {
	return (x[1] > y[1]);
}

bool cuscom1(string x, string y) {
	return (x[0] < y[0]);
}

void relax(int u, int v, int w) {
	if (dist[v] > dist[u]+w) {
		dist[v] = dist[u]+w;
		p[v] = u;
	} 
}

int coortoind(string x) {
	int ind = 0;
	ind += alphanum[x[0]];
	ind += (pseudo[stoi(x.substr(1, 1))]-1)*8;
	return ind;
}

string indtocoor(int x) {
	int y = (x/8);
	int xc;
	if (x%8 != 0) {
		y++;
		xc = x%8;
	}
	else {
		xc = 8;
	}
	char t = numalpha[xc];
	string coor = to_string(pseudo[y]);
	coor = t + coor;
	return coor;
}

void reset() {
	for (int i = 0; i < 70; i++) {
		bfs_num[i] = white;
		dist[i] = inf;
	}
}

void bfs(int x) {
	p[x] = -1;
	dist[x] = 0;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int u = q.front();
		for (int i = 0; i < al[u].size(); i++) {
			ii temp = al[u][i];
			int vtx = temp.first;
			int weight = temp.second;
			if (bfs_num[vtx] == white) {
				relax(u, vtx, weight);
				q.push(vtx);
			}
		}
		q.pop();
		bfs_num[u] = black;
	}

}

int main() {
	alphanum['a'] = 1;
	alphanum['b'] = 2;
	alphanum['c'] = 3;
	alphanum['d'] = 4;
	alphanum['e'] = 5;
	alphanum['f'] = 6;
	alphanum['g'] = 7;
	alphanum['h'] = 8;
	numalpha[1] = 'a';
	numalpha[2] = 'b';
	numalpha[3] = 'c';
	numalpha[4] = 'd';
	numalpha[5] = 'e';
	numalpha[6] = 'f';
	numalpha[7] = 'g';
	numalpha[8] = 'h';
	pseudo[1] = 8;
	pseudo[2] = 7;
	pseudo[3] = 6;
	pseudo[4] = 5;
	pseudo[5] = 4;
	pseudo[6] = 3;
	pseudo[7] = 2;
	pseudo[8] = 1;
	for (int i = 2; i < 10; i++) {
		for (int j = 2; j < 10; j++) {
			grid[i][j] = true;
		}
	}
	for (int i = 2; i < 10; i++) {
		for (int j = 2; j < 10; j++) {
			int ind = ((i-2)*8)+(j-1);
			if (grid[i-1][j-2]) {
				al[ind].emplace_back(ind-(8)-2, 1);
			}
			if (grid[i+1][j-2]) {
				al[ind].emplace_back(ind+(8)-2, 1);
			}
			if (grid[i-2][j-1]) {
				al[ind].emplace_back(ind-(8*2)-1, 1);
			}
			if (grid[i+2][j-1]) {
				al[ind].emplace_back(ind+(8*2)-1, 1);
			}
			if (grid[i-2][j+1]) {
				al[ind].emplace_back(ind-(2*8)+1, 1);
			}
			if (grid[i+2][j+1]) {
				al[ind].emplace_back(ind+(8*2)+1, 1);
			}
			if (grid[i-1][j+2]) {
				al[ind].emplace_back(ind-(8)+2, 1);
			}
			if (grid[i+1][j+2]) {
				al[ind].emplace_back(ind+(8)+2, 1);
			}
		}
	}
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		reset();
		string coor;
		cin >> coor;
		int ind = coortoind(coor);
		bfs(ind);
		int maxi = -1;
		for (int j = 0; j < 70; j++) {
			if (dist[j] != inf) {
				maxi = max(maxi, dist[j]);
			}
		}
		for (int j = 0; j < 70; j++) {
			if (dist[j] == maxi) {
				saver.insert(j);
			}
		}
		cout << maxi;
		unordered_set<int>::iterator itr;
		for (itr =saver.begin(); itr != saver.end(); itr++) {
			int temp = *itr;
			final.push_back(indtocoor(temp));
		}
		sort(final.begin(), final.end(), cuscom1);
		sort(final.begin(), final.end(), cuscom2);
		for (int j = 0; j < final.size(); j++) {
			cout << ' ' << final[j];
		}
		cout << endl;
		saver.clear();
		final.clear();
	}
}