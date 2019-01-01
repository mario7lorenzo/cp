#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int stream;
		cin >> stream;
		vector<int> saver;
		unordered_map<int, vector<int>> freq;
		unordered_set<int> curr;
		for (int i = 0; i < stream; i++) {
			int x;
			cin >> x;
			freq[x].push_back(i);
			saver.push_back(x);
		}
		int maxi = -1;
		int pointer = 0;
		int counter = 0;
		for (int i = 0; i < stream; i++) {
			if (curr.find(saver[i]) != curr.end()) {
				int ind;
				for (int j = 0; j < freq[saver[i]].size(); j++) {
					if (freq[saver[i]][j] == i) {
						ind = freq[saver[i]][j-1];
						break;
					}
				}
				maxi = max(maxi, counter);
				for (int j = pointer; j < ind; j++) {
					curr.erase(saver[j]);
					counter--;
				}
				pointer = ind+1;
			}
			else {
				curr.insert(saver[i]);
				counter++;
			}
		}
		maxi = max(maxi, counter);
		cout << maxi << endl;
	}
}