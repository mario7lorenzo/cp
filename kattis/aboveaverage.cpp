#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int total;
		cin >> total;
		int aver = 0;
		vector<int> lst;
		for (int j = 0; j < total; j++) {
			int x;
			cin >> x;
			aver += x;
			lst.push_back(x);
		}
		float above = 0.0;
		aver /= total;
		for (int k = 0; k < total; k++) {
			if (lst[k] > aver) {
				above++;
			}
		}
		float persen;
		persen = (above / total) * 100;
		cout << fixed << setprecision(3) << persen << "%" << endl;
	}
}