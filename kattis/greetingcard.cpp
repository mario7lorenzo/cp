#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	set<pair<ll, ll>> saver;
	int n;
	cin >> n;
	vector<pair<ll, ll>> helper;
	while (n--) {
		pair<ll, ll> p;
		cin >> p.first >> p.second;
		helper.push_back(p);
		saver.insert(p);
	}
	long long counter = 0;
	for (auto i : helper) {
		if (saver.find(make_pair(i.first+2018, i.second)) != saver.end()) {
			counter++;
		}
		if (saver.find(make_pair(i.first-2018, i.second)) != saver.end()) {
			counter++;
		}
		if (saver.find(make_pair(i.first, i.second+2018)) != saver.end()) {
			counter++;
		}
		if (saver.find(make_pair(i.first, i.second-2018)) != saver.end()) {
			counter++;
		}
		if (saver.find(make_pair(i.first+1680, i.second-1118)) != saver.end()) {
			counter++;
		}
		if (saver.find(make_pair(i.first+1680, i.second+1118)) != saver.end()) {
			counter++;
		}
		if (saver.find(make_pair(i.first-1680, i.second-1118)) != saver.end()) {
			counter++;
		}
		if (saver.find(make_pair(i.first-1680, i.second+1118)) != saver.end()) {
			counter++;
		}
		if (saver.find(make_pair(i.first+1118, i.second+1680)) != saver.end()) {
			counter++;
		}
		if (saver.find(make_pair(i.first+1118, i.second-1680)) != saver.end()) {
			counter++;
		}
		if (saver.find(make_pair(i.first-1118, i.second+1680)) != saver.end()) {
			counter++;
		}
		if (saver.find(make_pair(i.first-1118, i.second-1680)) != saver.end()) {
			counter++;
		}
		saver.erase(i);
	}
	cout << counter << endl;
}