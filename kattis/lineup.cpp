#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	string p;
	cin >> x;
	vector<string> lst;
	vector<string> copy;
	vector<string> lst_reversed;
	for (int i = 0; i < x; i++) {
		cin >> p;
		lst.push_back(p);
		copy.push_back(p);
	}
	int length = lst.size();
	std::sort (lst.begin(), lst.end());
	for (int i = x-1; i >= 0; i--) {
		lst_reversed.push_back(lst[i]);
	}
	if (copy == lst) {
		cout << "INCREASING" << endl;
	}
	else if (copy == lst_reversed) {
		cout << "DECREASING" << endl;
	}
	else {
		cout << "NEITHER" << endl;
	}
}