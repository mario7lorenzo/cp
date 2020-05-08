#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i=0; i < testcase; i++) {
		int sets;
		cin >> sets;
		long long n;
		cin >> n;
		vector<long long> track;
		track.push_back(n);
		while (n > 1) {
			if (n%2) {
				n = (n-1)/2;
				track.push_back(n);
			}
			else {
				n /= 2;
				track.push_back(n);
			}
		}
		reverse(track.begin(), track.end());
		pair<long long, long long> final = make_pair(1, 1);
		for (int j = 1; j < track.size(); j++) {
			if (track[j-1] * 2 == track[j]) {
				long long num = final.first;
				long long denom = final.second;
				denom += num;
				final = make_pair(num, denom);
			}
			else {
				long long num = final.first;
				long long denom = final.second;
				num += denom;
				final = make_pair(num, denom);
			}
		}
		cout << sets << ' ' << final.first << '/' << final.second << endl;
	}
}