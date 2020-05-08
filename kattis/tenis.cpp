#include <bits/stdc++.h>
using namespace std;

string satu, dua;

bool ev(int a, int b) {
	if (a == b) {
		return false;
	}
	if (a < b) {
		swap(a, b);
		swap(satu, dua);
	}
}

int main() {
	cin >> satu >> dua;
	int match;
	cin >> match;
	cin.ignore();
	for (int i = 0; i < match; i++) {
		int a = 0, b = 0;
		string lng;
		getline(cin, lng);
		int counter = 1;
		bool ab = true;
		bool valid = true;
		string acurr = "", bcurr = "";
		for (auto i : lng) {
					
		}	
	}
}