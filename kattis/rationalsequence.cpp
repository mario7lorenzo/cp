#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int sets;
		cin >> sets;
		string rat;
		cin >> rat;
		long long num;
		long long denom;
		string temp = "";
		vector<pair<long long, long long>> track;
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
		long long simpenatas = num;
		long long simpenbawah = denom;
		if (num == 1 && denom == 1) {
			cout << sets << " 1/2" << endl;
		}
		else if (num == 1) {
			long long sementara = denom;
			denom--;
			rat = to_string(sementara) + '/' + to_string(denom);
			cout << sets << ' ' << rat << endl;
		}
		else if (denom == 1) {
			long long sementara = num + 1;
			rat = "1/" + to_string(sementara);
			cout << sets << ' ' << rat << endl;
		}
		else {
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
			long long counter = 1;
			long long level = 0;
			for (long long k = 1; k < track.size(); k++) {
				cout << "ini pecahan " << track[k].first << ' ' << track[k].second << endl;
				if (track[k].first < track[k].second) {
					counter *= 2;
					cout << "ini counter skrg " << counter << endl;
					level++;
					cout << "ini level skrg " << level << endl;
				}
				else {
					counter = counter*2 + 1;
					cout << "ini counter skrg " << counter << endl;
					level++;
					cout << "ini level skrg " << level << endl;
				}
			}
			long long newn = counter + 1;
			if (counter%2) {
				cout << "ini level " << level << endl;
				long long delta = counter - pow(2, level);
				cout << "ini delta " << delta << endl;
				long long maxi = level - 2;
				cout << "ini maxi " << maxi << endl;
				maxi -= delta/2;
				cout << "ini maxi skrg " << maxi << endl;
				simpenatas += maxi;
				long long simpenan = simpenbawah;
				simpenbawah = simpenatas;
				cout << sets << ' ' << to_string(simpenan) << '/' << to_string(simpenbawah) << endl;
			}
			else {
				long long numer = track[track.size()-2].first;
				long long denomin = track[track.size()-2].second;
				numer += denomin;
				cout << sets << ' ' << to_string(numer) << '/' << to_string(denomin) << endl; 
			}
		}
	}
}
