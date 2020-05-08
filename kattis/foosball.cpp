#include <bits/stdc++.h>

using namespace std;

int main() {
	int players;
	cin >> players;
	string wo = "", bo = "", wd = "", bd = "";
	queue<string> q;
	unordered_map<string, int> enter;
	for (int i = 0; i < players; i++) {
		string x;
		cin >> x;
		if (wo == "") {
			wo = x;
		}
		else if (bo == "") {
			bo = x;
		}
		else if (wd == "") {
			wd = x;
		}
		else if (bd == "") {
			bd = x;
		}
		else {
			q.push(x);
		}
		enter[x] = i;
	}
	string res;
	cin >> res;
	int counter = 0;
	char bw;
	map<int, vector<pair<string, string>>> saver;
	pair<string, string> curr;
	int streak = 0;
	for (auto i : res) {
		if (!counter) {
			bw = i;
			if (i == 'W') {
				curr = make_pair(wo, wd);
				swap(wo, wd);
				q.push(bd);
				bd = bo;
				bo = q.front();
				q.pop();
				enter[bo] = players;
			}
			else {
				curr = make_pair(bo, bd);
				swap(bo, bd);
				q.push(wd);
				wd = wo;
				wo = q.front();
				q.pop();
				enter[wo] = players;
			}
			streak++;
		}
		else if (i != bw) {
			bw = i;
			saver[streak].push_back(curr);
			if (i == 'W') {
				swap(wo, wd);
				if (enter[wo] < enter[wd]) {
					curr = make_pair(wo, wd);
				}
				else {
					curr = make_pair(wd, wo);
				}
				q.push(bd);
				bd = bo;
				bo = q.front();
				q.pop();
				enter[bo] = players;
			}
			else {
				swap(bo, bd);
				if (enter[bo] < enter[bd]) {
					curr = make_pair(bo, bd);
				}
				else {
					curr = make_pair(bd, bo);
				}
				q.push(wd);
				wd = wo;
				wo = q.front();
				q.pop();
				enter[wo] = players;
			}
			streak = 1;
		}
		else if (bw == i) {
			streak++;
			if (i == 'W') {
				swap(wo, wd);
				q.push(bd);
				bd = bo;
				bo = q.front();
				q.pop();
				enter[bo] = players;
			}
			else {
				swap(bo, bd);
				q.push(wd);
				wd = wo;
				wo = q.front();
				q.pop();
				enter[wo] = players;
			}			
		}
		counter++;
		players++;
	}
	int maxi = -1;
	saver[streak].push_back(curr);
	for (auto it = saver.begin(); it != saver.end(); it++) {
		if (it->second.size() != 0) {
			maxi = max(maxi, it->first);
		}
	}
	for (int i = 0; i < saver[maxi].size(); i++) {
		cout << saver[maxi][i].first << ' ' << saver[maxi][i].second << endl;
	}
}