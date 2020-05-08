#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		vector<pair<long long, long long>> track;
		int sets;
		cin >> sets;
		string rat;
		cin >> rat;
		long long num;
		long long denom;
		string temp = "";
		for (int j = 0; j < rat.length(); j++) {
			if (rat[j] == '/') {
				num = stoll(temp);
				temp = "";
			}
			else {
				temp += rat[j];
			}
		}
		denom = stoll(temp);
		track.push_back(make_pair(num, denom));
		while (rat != "1/1") {
			if (num > denom) {
				num -= denom;
				rat = to_string(num) + '/' + to_string(denom);
				track.push_back(make_pair(num, denom));
			}
			else {
				denom -= num;
				rat = to_string(num) + '/' + to_string(denom);
				track.push_back(make_pair(num, denom));
			}
		}
		reverse(track.begin(), track.end());
		// for (int k = 0; k < track.size(); k++) {
		// 	cout << track[k].first << track[k].second << endl;
		// }
		long long counter = 1;
		for (long long i = 1; i < track.size(); i++) {
			if (track[i].first > track[i].second) {
				counter = 2*counter + 1;
			}
			else {
				counter *= 2;
			}
		}
		cout << sets << ' ' << counter << endl;
	}
}