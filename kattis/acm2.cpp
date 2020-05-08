#include <bits/stdc++.h>
using namespace std;

int main() {
	int actt = 0;
	int pent = 0;
	int minut;
	int n, pref;
	cin >> n >> pref;
	vector<int> saver;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i == pref) {
			minut = x;
		}
		else {
			saver.push_back(x);
		}
	}
	sort(saver.begin(), saver.end());
	saver.push_back(minut);
	int ind = saver.size()-1;
	int solved = 0;
	while (actt+saver[ind%saver.size()] <= 300) {
		if (ind == 2*saver.size()-1) {
			break;
		}
		solved++;
		actt += saver[ind%saver.size()];
		pent += actt;
		ind++;
	}
	cout << solved << ' ' << pent << endl;
}