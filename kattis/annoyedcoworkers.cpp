#include<bits/stdc++.h>
using namespace std;

int main() {
	int h, c;
	cin >> h >> c;
	vector<long long> initialEmotions;
	vector<long long> increment;
	priority_queue<pair<long long, int>> pq;
	for (int i = 0; i < c; i++) {
		long long a, d;
		cin >> a >> d;
		initialEmotions.push_back(a);
		increment.push_back(d);
		pq.push(make_pair(-a-d, i));
	}

	for (int i = 0; i < h; i++) {
		pair<long long, int> p = pq.top();
		pq.pop();

		long long e = p.first;
		long long w = p.second;

		p = make_pair(e-increment[w], w);
		pq.push(p);
	}

	long long maxi = -1e9;
	while (pq.size() > 0) {
		pair<long long, int> p = pq.top();
		pq.pop();

		long long e = p.first;
		long long w = p.second;
		e += increment[w];

		maxi = max(maxi, -e);
	}

	cout << maxi << endl;
}