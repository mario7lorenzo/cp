#include <bits/stdc++.h>
using namespace std;

int main() {
	int targets;
	cin >> targets;
	vector<vector<int>> saver;
	for (int i = 0; i < targets; i++) {
		string shape;
		cin >> shape;
		vector<int> temp;
		if (shape == "rectangle") {
			temp.push_back(1);
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			temp.push_back(x1);
			temp.push_back(y1);
			temp.push_back(x2);
			temp.push_back(y2);
		}
		else if (shape == "circle") {
			temp.push_back(0);
			int x, y, r;
			cin >> x >> y >> r;
			temp.push_back(x);
			temp.push_back(y);
			temp.push_back(r);
		}
		saver.push_back(temp);
	}
	int shots;
	cin >> shots;
	for (int i = 0; i < shots; i++) {
		int x, y;
		cin >> x >> y;
		int counter = 0;
		for (int j = 0; j < saver.size(); j++) {
			if (saver[j][0] == 1) {
				if (x >= min(saver[j][1], saver[j][3]) && x <= max(saver[j][1], saver[j][3]) && y <= max(saver[j][2], saver[j][4]) && y >= min(saver[j][2], saver[j][4])) {
					counter++;
				}
			}
			else if (saver[j][0] == 0) {
				if ((pow(((pow(double(x-saver[j][1]), 2.0) + pow(double(y-saver[j][2]), 2.0))), 0.5)) <= saver[j][3]) {
					counter++;
				}
			}
		}
		cout << counter << endl;
	}
}