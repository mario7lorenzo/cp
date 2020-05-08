#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> saver;
	for (int i = 0; i < 8; i++) {
		int x;
		cin >> x;
		saver.push_back(x);
	}
	map<int, int> prime;
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	prime[3] = 7;
	prime[4] = 11;
	prime[5] = 13;
	prime[6] = 17;
	prime[7] = 19;
	int counter = 0;
	bool overflow = false;
	while (!overflow) {
		// cout << "tes" << endl;
		bool inc = true;
		while (inc) {
			inc = false;
			saver[0]++;
			for (int i = 0; i < 8; i++) {
				saver[i] = saver[i]%prime[i];
				if (saver[i] != 0) {
					counter++;
					inc = true;
					break;
				}
				else if (saver[i] == 0 && i == 7) {
					overflow = true;
					inc = false;
					break;
				}
				else {
					saver[i+1]++;
				}
			}
			if (overflow) {
				break;
			}
		}
	}
	cout << counter << endl;
}