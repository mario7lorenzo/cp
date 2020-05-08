#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	bool isfirst = true;
	vector<pair<string, vector<double>>> saver;
	while (cin >> n, n != 0) {
		if (isfirst) {
			isfirst = false;
		}
		else {
			cout << endl;
		}
		for (int i = 0; i < n; i++) {
			string sz;
			double x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2 >> sz;
			vector<double> temp;
			temp.push_back(x1);
			temp.push_back(y1);
			temp.push_back(x2);
			temp.push_back(y2);
			saver.emplace_back(sz, temp);
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			double x, y;
			string stat;
			cin >> x >> y >> stat;
			// cout << x << y << stat << endl;
			bool exist = false;
			string stas;
			for (int j = 0; j < n; j++) {
				vector<double> otto = saver[j].second;
				// cout << "tes" << endl;
				if (x >= otto[0] && x <= otto[2] && y >= otto[1] && y <= otto[3]) {
					exist = true;
					if (stat == saver[j].first) {
						stas = "correct";
					}
					else {
						stas = saver[j].first;
					}
					break;
				}
			}
			if (exist) {
				cout << stat << ' ' << stas << endl;
			}
			else {
				cout << stat << " floor" << endl;
			}
		}
		saver.clear();
	}
}