#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

int prime_dec(int c) {
	int counter = 0;
	int ind = 0;
	int sz = primes.size();
	while (c != 1) {
		if (ind == sz) {
			break;
		} 
		if (c%(primes[ind]) == 0) {
			counter++;
			c /= primes[ind];
		} else {
			ind++;
		}
	}
	return ind == sz ? counter + 1 : counter;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int x;
	cin >> x;
	bool arr[32010];
	for (int i = 0; i < 32010; i++) {
		arr[i] = true;
	}
	arr[0] = false;
	arr[1] = false;
	for (int i = 2; i < 32010; i++) {
		if (arr[i]) {
			primes.push_back(i);
			for (int j = 2 * i; j < 32010; j+= i) {
				arr[j] = false;
			}
		}
	}
	cout << prime_dec(x) << endl;
}