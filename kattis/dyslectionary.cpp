#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
using namespace std;
string rev(string a) {
	int x = a.length();
	for (int i = 0; i < x/2; i++) {
		swap(a[i], a[x-i-1]);
	}
	return a;
}
 
int main() {
	string p;
	vector<string> lst;
	while (getline(cin, p)) {
		if (p == "") {
			for (int i = 0; i < lst.size(); i++) {
				lst[i] = rev(lst[i]);
			}
			stable_sort(lst.begin(), lst.end());
			for (int i = 0; i < lst.size(); i++) {
				lst[i] = rev(lst[i]);
			}
			int max_len = 0;
			for (int i = 0; i < lst.size(); i++) {
				if (max_len < lst[i].length()) {
					max_len = lst[i].length();
				}
			}
			for (int i = 0; i < lst.size(); i++) {
				while (lst[i].length() < max_len) {
					lst[i] = ' ' + lst[i];
				}
			}
			for (int i = 0; i < lst.size(); i++) {
				cout << lst[i] << endl;
			}
			cout << endl;
			lst.clear();
		}
		else {
			lst.push_back(p);
		}
	}
	for (int i = 0; i < lst.size(); i++) {
		lst[i] = rev(lst[i]);
	}
	stable_sort(lst.begin(), lst.end());
	for (int i = 0; i < lst.size(); i++) {
		lst[i] = rev(lst[i]);
	}
	int max_len = 0;
	for (int i = 0; i < lst.size(); i++) {
		if (max_len < lst[i].length()) {
			max_len = lst[i].length();
		}
	}
	for (int i = 0; i < lst.size(); i++) {
		while (lst[i].length() < max_len) {
			lst[i] = ' ' + lst[i];
		}
	}
	for (int i = 0; i < lst.size(); i++) {
		cout << lst[i] << endl;
	}	
}