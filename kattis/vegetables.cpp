#include <bits/stdc++.h>
using namespace std;

int main() {
	double t;
	int n;
	cin >> t >> n;
	int currcut[1000];
	unordered_map<double, priority_queue<int>> id1; 
	priority_queue<double> pq;
	vector<double> ori;
	double mini = 1000001.0;
	while (n--) {
		double x;
		cin >> x;
		pq.push(x);
		ori.push_back(x);
		mini = min(mini, x);
	}
	sort(ori.rbegin(), ori.rend());
	for (int i = 0; i < ori.size(); i++) {
		currcut[i] = 1;
		id1[ori[i]].push(i);
	}
	int totcut = 0;
	while (mini/pq.top() < t) {
		double maxi = pq.top();
		pq.pop();
		int id = id1[maxi].top();
		id1[maxi].pop();
		double original = ori[id];
		currcut[id]++;
		double res = original/currcut[id];
		mini = min(mini, res);
		pq.push(res);
		id1[res].push(id);
		totcut++;
	}
	cout << totcut << endl;
}