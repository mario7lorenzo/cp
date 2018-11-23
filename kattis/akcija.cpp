#include <bits/stdc++.h>
using namespace std;

int main() {
	int books;
	cin >> books;
	vector<int> price;
	long long prices;
	long long total = 0;
	long long disc = 0;
	for (int i = 0; i < books; i++) {
		int x;
		cin >> x;
		price.push_back(x);
		total += x;
	}
	sort(price.begin(), price.end());
	if (price.size()%3 == 0) {
		for (int i = 0; i < price.size(); i+= 3) {
			disc += price[i];
		}
	}
	else if (price.size()%3 == 1) {
		for (int i = 1; i < price.size(); i+= 3) {
			disc += price[i];
		}
	}
	else {
		for (int i = 2; i < price.size(); i+= 3) {
			disc += price[i];
		}
	}
	cout << total - disc << endl;
}