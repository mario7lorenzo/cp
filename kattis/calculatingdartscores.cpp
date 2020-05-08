#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<int, vector<pair<int, int>>> saver;
	int ctr = 1, ctr2 = 1, ctr3 = 1;
	while (ctr <= 20) {
		vector<pair<int, int>> tmp;
		for (int i = 1; i <= 3; i++) {
			tmp.push_back(make_pair(i, ctr));
			saver[i*ctr] = tmp;
			tmp.clear();
		}
		ctr++;
	}
	ctr = 1;
	while (ctr <= 20) {
		vector<pair<int, int>> temp;
		for (int i = 1; i <= 3; i++) {
			ctr2 = 1;
			temp.push_back(make_pair(i, ctr));
			while (ctr2 <= 20) {
				for (int j = 1; j <= 3; j++) {
					temp.push_back(make_pair(j, ctr2));
					saver[(i*ctr) + (j*ctr2)] = temp;
					temp.erase(temp.begin()+1);
				}
				ctr2++;
			}
			temp.clear();
		}
		ctr++;
	}
	ctr = 1; ctr2 = 1;
	while (ctr <= 20) {
		vector<pair<int, int>> temp;
		for (int i = 1; i <= 3; i++) {
			temp.push_back(make_pair(i, ctr));
			ctr2 = 1;
			while (ctr2 <= 20) {
				// cout << ctr2 << endl;
				for (int j = 1; j <= 3; j++) {
					ctr3 = 1;
					temp.push_back(make_pair(j, ctr2));
					while (ctr3 <= 20) {
						for (int k = 1; k <= 3; k++) {
							temp.push_back(make_pair(k, ctr3));
							saver[(i*ctr)+(j*ctr2)+(k*ctr3)] = temp;
							temp.erase(temp.begin()+2);
						}
						ctr3++;
					}
					temp.erase(temp.begin()+1);
				}
				ctr2++;
			}
			temp.clear();
		}
		ctr++;
	}
	int num;
	cin >> num;
	if (saver.find(num) == saver.end()) {
		cout << "impossible" << endl;
	}
	else {
		vector<pair<int, int>> o = saver[num];
		for (auto i : o) {
			if (i.first == 1) {
				cout << "single ";
			}
			else if (i.first == 2) {
				cout << "double ";
			}
			else if (i.first == 3) {
				cout << "triple ";
			}
			cout << i.second << endl;
		}
	}
}