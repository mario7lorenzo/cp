#include <bits/stdc++.h>
using namespace std;

int main() {
	string words;
	cin >> words;
	int days = 0;
	for (int i = 0; i < words.length(); i++) {
		if ((i+1)%3==1) {
			if (words[i] != 'P') {
				days++;
			}
		}
		if ((i+1)%3==2) {
			if (words[i] != 'E') {
				days++;
			}
		}
		if ((i+1)%3==0) {
			if (words[i] != 'R') {
				days++;
			}
		}
	}
	cout << days << endl;
}