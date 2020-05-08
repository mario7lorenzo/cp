#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<int, int> saver;
	vector<int> lst;
	for (int i = 0; i < n; i++) {
		int res;
		cin >> res;
		saver[res]++;
		lst.push_back(res);
	}
	map<int, int>::iterator itr;
	int curr = 0;
	for (itr = saver.begin(); itr != saver.end(); itr++) {
		if (itr->second == 1) {
			curr = itr->first;
		}
	}
	if (curr == 0) {
		cout << "none" << endl;
	}
	else {
		for (int i = 1; i < lst.size()+1; i++) {
			if (lst[i-1] == curr) {
				cout << i << endl;
				break;
			}
		}
	}
}