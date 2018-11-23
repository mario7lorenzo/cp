#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int total;
		cin >> total;
		unordered_map<long long, int> mapp;
		for (int j = 0; j < total; j++) {
			long long number;
			cin >> number;
			if (mapp.find(number) == mapp.end()) {
				mapp[number] = 1;
			}
			else {
				mapp[number] += 1;
			}
		}
		unordered_map<long long, int>:: iterator itr;
		for (itr = mapp.begin(); itr != mapp.end(); itr++) {
			if (itr->second == 1) {
				cout << "Case #" << i+1 << ": " << itr->first << endl;
				break; 
			}
		}
	}
}