#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, y;
	cin >> n >> y;
	set<int> obs;
	for (int i = 0; i < n; i++) {
		obs.insert(i);
	}
	for (int i = 0; i < y; i++) {
		int no;
		cin >> no;
		if (obs.find(no) != obs.end()) {
			obs.erase(no);
		}
	}
	set<int>::iterator i;
	for (i = obs.begin(); i != obs.end(); i++) {
		cout << *i << endl;
	}
	cout << "Mario got " << n-obs.size() << " of the dangerous obstacles." << endl;
}