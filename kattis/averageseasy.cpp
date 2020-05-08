#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin.ignore();
		int cs, e;
		cin >> cs >> e;
		double avgcs = 0, avge = 0;
		vector<int> saver;
		for (int i = 0; i < cs; i++) {
			int x;
			cin >> x;
			avgcs += x;
			saver.push_back(x);
		}
		for (int i = 0; i < e; i++) {
			int x;
			cin >> x;
			avge += x;
		}
		int counter = 0;
		avgcs /= cs;
		avge /= e;
		for (int i = 0; i < cs; i++) {
			if (saver[i] < avgcs && saver[i] > avge) {
				counter++;
			}
		}
		cout << counter << endl;
	}
}