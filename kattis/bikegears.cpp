#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool compare_ratio(pair<ll,ll> r1, pair<ll,ll> r2) {
	if(r1.first * r2.second == r2.first * r1.second) {
        return r1.first < r2.first;
    }
    return r1.first*r2.second < r2.first*r1.second;
}

int main() {
	int f, b;
	cin >> f >> b;

	vector<ll> fs, bs;

	for (int i = 0; i < f; i++) {
		ll elem;
		cin >> elem;

		fs.push_back(elem);
	}

	for (int i = 0; i < b; i++) {
		ll elem;
		cin >> elem;
		bs.push_back(elem);
	}

	vector<pair<ll, ll> > pairs;

	for (int i = 0; i < f; i++) {
		for (int j = 0; j < b; j++) {
			pairs.push_back(make_pair(fs[i], bs[j]));
		}
	}

	sort(pairs.begin(), pairs.end(), compare_ratio);

	for (pair<ll, ll> p : pairs){
		cout << "(" << p.first << "," << p.second << ")" << endl;
	}
}