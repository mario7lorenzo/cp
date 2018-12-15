#include <bits/stdc++.h>
using namespace std;

int n, h, w, dist;
int globfreq[50][50];
bool cuscom1(pair<int, pair<int, int>> x, pair<int, pair<int, int>> y) {
	return x.second.second > y.second.second;
}

bool cuscom2(pair<int, pair<int, int>> x, pair<int, pair<int, int>> y) {
	return x.second.first > y.second.first;
}

bool cuscom3(pair<int, pair<int, int>> x, pair<int, pair<int, int>> y) {
	return x.first < y.first;
}

void reset() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			globfreq[i][j] = 0;
		}
	}
}

int main() {
	while (cin >> n >> h >> w) {
		if (n == 0 &&  h== 0 && w == 0) {
			break;
		}
		map<char, vector<pair<int, pair<int, int>>>> jack;
		map<char, queue<pair<int, int>>> jacker;
		map<char, pair<int, int>> id;
		vector<pair<int, int>> trees;
		map<char, double> score;
		char grid[h][w];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char x;
				cin >> x;
				grid[i][j] = x;
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (grid[i][j] != '!' && grid[i][j] != '.') {
					id[grid[i][j]] = make_pair(i, j);
					score[grid[i][j]] = 0.0;
				}
				else if (grid[i][j] == '!') {
					trees.emplace_back(i, j);
				}
			}
		}
		map<char, pair<int, int>>::iterator i;
		for (i = id.begin(); i != id.end(); i++) {
			char lum = i->first;
			int xlum = i->second.first;
			int ylum = i->second.second;
			queue<pair<int, pair<int, int>>> q;
			for (int j = 0; j < trees.size(); j++) {
				int xever = trees[j].first, yever = trees[j].second;
				dist = pow(abs(xever-xlum), 2) + pow(abs(yever-ylum), 2);
				jack[lum].emplace_back(dist, make_pair(xever, yever));
			}
		}
		map<char, vector<pair<int, pair<int, int>>>>::iterator itr;
		for (itr = jack.begin(); itr != jack.end(); itr++) {
			// cout << "ini id " << itr->first << endl;
			vector<pair<int, pair<int, int>>> temp = itr->second;
			sort(temp.begin(), temp.end(), cuscom2);
			stable_sort(temp.begin(), temp.end(), cuscom1);
			stable_sort(temp.begin(), temp.end(), cuscom3);
			queue<pair<int, int>> tempq;
			for (int i = 0; i < temp.size(); i++) {
				tempq.push(temp[i].second);
			}
			jacker[itr->first] = tempq;
		}
		while (n--) {
			reset();
			map<char, queue<pair<int, int>>>::iterator it;
			map<char, pair<int, int>> cut;
			for (it = jacker.begin(); it != jacker.end(); it++) {
				bool available = false;
				while (!available) {
					if (it->second.empty()) {
						break;
					}
					pair<int, int> curr = it->second.front();
					it->second.pop();
					int currx = curr.first, curry = curr.second;
					if (grid[currx][curry] == '!') {
						cut[it->first] = curr;
						available = true;
						globfreq[currx][curry]++;
					}
				}
			}
			map<char, pair<int, int>>::iterator otto;
			for (otto = cut.begin(); otto != cut.end(); otto++) {
				char play = otto->first;
				int coorx = otto->second.first, coory = otto->second.second;
				score[play] += 1.0/globfreq[coorx][coory];
				grid[coorx][coory] = '.';
			}
			cut.clear();
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << grid[i][j];
			}
			cout << endl;
		}
		map<char, double>::iterator xxx;
		for (xxx = score.begin(); xxx != score.end(); xxx++) {
			cout << fixed << setprecision(5) << xxx->first << ' ' << xxx->second << endl;
		}
	}
}