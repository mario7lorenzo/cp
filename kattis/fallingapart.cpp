#include <bits/stdc++.h>
using namespace std;

int main() {
	int data;
	cin >> data;
	vector<int> saver;
	int alice = 0;
	int bob = 0;
	for (int i = 0; i < data; i++) {
		int num;
		cin >> num;
		saver.push_back(num);
	}
	sort(saver.begin(), saver.end(), greater<int>());
	for (int i = 0; i < data; i++) {
		if (i%2 == 0) {
			alice += saver[i];
		}
		else {
			bob += saver[i];
		}
	}
	cout << alice << ' ' << bob << endl;
}