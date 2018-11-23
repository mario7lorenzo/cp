#include <bits/stdc++.h>
using namespace std;

int main() {
	map<char, int> saver; 
	for (int i = 0; i < 5; i++) {
		string card;
		cin >> card;
		if (saver.find(card[0]) == saver.end()) {
			saver[card[0]] = 1;
		}
		else {
			saver[card[0]]++;
		}
	}
	map<char, int>::iterator itr;
	int maxi = -1;
	for (itr = saver.begin(); itr != saver.end(); itr++) {
		if (itr->second > maxi) {
			maxi = itr->second;
		}
	}
	cout << maxi << endl;
}