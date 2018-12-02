#include <bits/stdc++.h>
using namespace std;

int main() {
	long long pokenom, k;
	cin >> pokenom >> k;
	unordered_set<long long> final;
	vector<pair<long long, long long>> attack;
	vector<pair<long long, long long>> defense;
	vector<pair<long long, long long>> health;
	vector<pair<long long, vector<long long>>> lst;
	for (long long i = 0; i < pokenom; i++) {
		long long att, def, hlt;
		cin >> att >> def >> hlt;
		attack.emplace_back(att, i);
		defense.emplace_back(def, i);
		health.emplace_back(hlt, i);
	}
	sort(health.rbegin(), health.rend());
	sort(attack.rbegin(), attack.rend());
	sort(defense.rbegin(), defense.rend());
	for (long long i = 0; i < k; i++) {
		long long hltnow = health[i].second;
		long long defnow = defense[i].second;
		long long attnow = attack[i].second; 
		if (final.find(hltnow) == final.end()) {
			final.insert(hltnow);
		}
		if (final.find(defnow) == final.end()) {
			final.insert(defnow);
		}
		if (final.find(attnow) == final.end()) {
			final.insert(attnow);
		}
	}
	cout << final.size() << endl;
}