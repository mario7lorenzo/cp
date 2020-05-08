#include <bits/stdc++.h>
using namespace std;

int main() {
	string lst;
	cin >> lst;
	char init = lst[0];
	int adj1 = 0, adj2 = 0, adj3 = 0;
	char curr = init;
	for (int i = 1; i < lst.length(); i++) {
		if (i == 1) {
			if (init == lst[i]) {
				if (init == 'D') {
					adj1++;
				}
			}
			else {
				if (init == 'D') {
					adj1++;
				}
				else {
					adj1 += 2;
				}
			}
		}
		else {
			if (lst[i] == 'D') {
				adj1 += 2;
			}
		}
	}
	for (int i = 1; i < lst.length(); i++) {
		if (i == 1) {
			if (init == lst[i]) {
				if (init == 'U') {
					adj2++;
				}
			}
			else {
				if (init == 'U') {
					adj2++;
				}
				else {
					adj2 += 2;
				}
			}
		}
		else {
			if (lst[i] == 'U') {
				adj2 += 2;
			}
		}
	}
	for (int i = 1; i < lst.length(); i++) {
		if (curr != lst[i]) {
			adj3++;
		}
		curr = lst[i];
	}
	cout << adj1 << endl;
	cout << adj2 << endl;
	cout << adj3 << endl;
}