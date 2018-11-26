#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> saver;
unordered_map<char, bool> solver;

int main() {
	int mnt;
	while (cin >> mnt, mnt != -1) {
		char prob;
		string statuses;
		cin >> prob >> statuses;
		solver[prob] = false;
		if (statuses == "wrong") {
			saver[prob] += 20;
		}
		else {
			saver[prob] += mnt;
			solver[prob] = true;
		}
	}
	unordered_map<char, int>::iterator itr;
	int solved = 0;
	int totmin = 0;
	for (itr = saver.begin(); itr != saver.end(); itr++) {
		char problem = itr->first;
		if (solver[problem]) {
			solved++;
			totmin += itr->second;
		}
	}
	cout << solved << ' ' << totmin << endl;
}