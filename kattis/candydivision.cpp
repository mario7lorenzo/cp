#include <bits/stdc++.h>
using namespace std;


int main() {
	set<long long> fact;
	long long n;
	cin >> n;
	long long temp = pow(n, 0.5)+1;
	long long x = 1;
	while (x <= temp) {
		if (n%x == 0) {
			fact.insert(x);
			fact.insert(n/x);
		} 
		x++;
	}
	bool isfirst = true;
	for (auto i : fact) {
		if (isfirst) {
			cout << i-1;
			isfirst = false;
		}
		else {
			cout << ' ' << i-1;
		}
	}
	cout << endl;
}