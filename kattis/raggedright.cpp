#include <bits/stdc++.h>
using namespace std;

int main() {
	string p;
	vector<int> storer;
	int counter = 0;
	while (getline(cin, p)) {
		int x;
		x = p.length();
		storer.push_back(x);
	}
	int maxi = -999999999;
	for (int i = 0; i < storer.size(); i++) {
		if (maxi < storer[i]) {
			maxi = storer[i];
		}
	}
	for (int i = 0; i < storer.size()-1; i++) {
		counter += pow((maxi - storer[i]), 2);
	}
	cout << counter << endl;
}