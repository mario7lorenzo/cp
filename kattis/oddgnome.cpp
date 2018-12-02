#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int gnome;
		cin >> gnome;
		int curr = -1e9;
		int pos = -1;
		vector<int> saver;
		for (int i = 1; i < gnome+1; i++) {
			int num;
			cin >> num;
			saver.push_back(num);
		}
		for (int i = 1; i < saver.size(); i++) {
			if (saver[i]-saver[i-1] != 1) {
				cout << i+1 << endl;
				break;
			}
			else if (saver[i+1]-saver[i] != 1) {
				cout << i+2 << endl;
				break;
			}
		}
	}
}