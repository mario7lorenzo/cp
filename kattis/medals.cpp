#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	while (n) {
		unordered_map<string, pair<int, pair<int, int>>> medals;

		int totalmedals = 0;
		vector<string> countries;
		for (int i = 0; i < n; i++) {
			string country;
			int g,s,b;
			cin >> country >> g >> s >> b;
			totalmedals += g+s+b;
			medals[country] = {g,{s,b}};
			countries.push_back(country);
		}

		bool exists = false;
		for (int j = 0; j <= 2; j++) {
			for (int k = 0; k <= 2; k++) {
				for (int l = 0; l <= 2; l++) {
					pair<int, pair<int, int>> canada_medal = medals["Canada"];
					double canada_score = pow(totalmedals, j)*canada_medal.first + pow(totalmedals, k)*canada_medal.second.first + pow(totalmedals, l)*canada_medal.second.second;

					double best_score = canada_score;

					for (string country: countries) {
						pair<int, pair<int, int>> medal = medals[country];
						double score = pow(totalmedals, j)*medal.first + pow(totalmedals, k)*medal.second.first + pow(totalmedals, l)*medal.second.second;
						best_score = max(best_score, score);
					}

					if (canada_score == best_score) {
						// cout << j << ' ' << k << ' ' << l << endl;
						exists = true;
					}

				}
			}
		}

		cout << (exists ? "Canada wins!" : "Canada cannot win.") << endl;
		cin >> n;
	}
}