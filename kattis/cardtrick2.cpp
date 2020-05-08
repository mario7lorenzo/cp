#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<vector<int>> precal;
	for (int i = 1; i <= 13; i++) {
		queue<int> q;
		int arr[i];
		for (int j = 0; j < i; j++) {
			q.push(j);
		}
		for (int j = 1; j <= i; j++) {
			for (int k = 0; k < j; k++) {
				int temp = q.front();
				q.pop();
				q.push(temp);
			}
			int fr = q.front();
			q.pop();
			arr[fr] = j;
		}
		vector<int> res;
		for (int j = 0; j < i; j++) {
			res.push_back(arr[j]);
		}
		precal.push_back(res);
	}
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> fin = precal[n-1];
		for (auto i : fin) {
			cout << i << ' ';
		}
		cout << endl;
	}
}