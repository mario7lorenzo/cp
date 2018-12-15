#include <bits/stdc++.h>
using namespace std;

int main() {
	int w, n;
	int clouds = 1;
	while (cin >> w >> n, w != 0 && n != 0) {
		vector<pair<string, int>> saver;
		vector<pair<string, pair<int, int>>> final;
		int maxocc = -1;
		for (int i = 0; i < n; i++) {
			string name;
			int occ;
			cin >> name >> occ;
			if (occ >= 5) {
				maxocc = max(maxocc, occ);
				saver.emplace_back(name, occ);
			}
		}
		for (int i = 0; i < n; i++) {
			int h, l;
			if ((40*(saver[i].second - 4))%(maxocc-4) != 0) {
				h = 8 + ((40*(saver[i].second - 4))/(maxocc-4)) + 1;
			}
			else {
				h = 8 + ((40*(saver[i].second - 4))/(maxocc-4));
			}
			if ((9 * saver[i].first.length() * h)% 16 != 0) {
				l = ((9 * saver[i].first.length() * h)/16)+1;
			} 
			else {
				l = ((9 * saver[i].first.length() * h)/16);
			}
			final.emplace_back(saver[i].first, make_pair(h, l));
		}
		int totheight = 0, currheight = -1, currwidth = 0;
		bool isfirst = true;
		for (int i = 0; i < final.size(); i++) {
			if (isfirst) {
				currheight = final[i].second.first;
				currwidth = final[i].second.second;
				isfirst = false;
			}
			else {
				if (currwidth + final[i].second.second + 10 > w) {
					totheight += currheight;
					currheight = final[i].second.first;
					currwidth = final[i].second.second;
				}
				else {
					currheight = max(currheight, final[i].second.first);
					currwidth += final[i].second.second + 10;
				}
			}
			// cout << "ini currhegiht " << currheight << endl;
			// cout << "ini currwidth " << currwidth << endl;
		}
		totheight += currheight;
		cout << "CLOUD " << clouds << ": " << totheight << endl;
		clouds++;
	}
}