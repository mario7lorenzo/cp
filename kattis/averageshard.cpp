#include <bits/stdc++.h>
using namespace std;

int main() {
	long long testcase;
	cin >> testcase;
	for (long long i = 0; i < testcase; i++) {
		cin.ignore();
		long long cs, e;
		cin >> cs >> e;
		long long totcs = 0, tote = 0;
		vector<long long> saver;
		for (long long i = 0; i < cs; i++) {
			long long x;
			cin >> x;
			totcs += x;
			saver.push_back(x);
		}
		for (long long i = 0; i < e; i++) {
			long long x;
			cin >> x;
			tote += x;
		}
		long long counter = 0;
		double avgcs = double(totcs) / cs;
		double avge = double(tote) / e;
		for (long long i = 0; i < cs; i++) {
			if (saver[i] < avgcs && saver[i] > avge) {
				counter++;
			}
		}
		cout << counter << endl;
	}
}