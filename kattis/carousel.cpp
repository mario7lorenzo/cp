#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m, !(n == 0 && m == 0)) {
		double curr = 1e9;
		double maxi = -1;
		double tic = 0;
		double a, b;
		while (n--) {
			cin >> a >> b;
			if (a > m) {
				continue;
			}
			if (b/a < curr || (b/a == curr && a > maxi)) {
				curr = b/a;
				maxi = a;
				tic = b;
			}
		}
		if (curr == 1e9) {
			cout << "No suitable tickets offered" << endl;
		}
		else {
			cout << "Buy " << maxi << " tickets for $" << tic << endl; 
		}
	}
}