#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int city;
		cin >> city;
		unordered_set<string> saver;
		int counter = 0;
		for (int j = 0; j < city; j++) {
			string temp;
			cin >> temp;
			if (saver.find(temp) == saver.end()) {
				counter++;
				saver.insert(temp);
			}
		}
		cout << counter << endl;
	}
}