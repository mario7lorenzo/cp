#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		deque<int> students;
		for (int i = 0; i < 3*n; i++) {
			int x;
			cin >> x;
			students.push_back(x);
		}
		sort(students.begin(), students.end());
		deque<int> saver;
		for (int i = 0; i < 3*n; i++) {
			saver.push_back(students[i]);
		}
		int tot = 0;
		for (int i = 0; i < n; i++) {
			saver.pop_front();
			saver.pop_back();
			tot += saver.back();
			saver.pop_back();
		}
		cout << tot << endl;
	}
}