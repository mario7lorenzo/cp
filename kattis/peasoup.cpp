#include <bits/stdc++.h>
using namespace std;

int main() {
	int rest;
	cin >> rest;
	bool done = false;
	while (rest--) {
		int menu;
		cin >> menu;
		string name;
		string dumb;
		getline(cin, dumb);
		getline(cin, name);
		bool peasoup = false, pancakes = false;
		for (int i = 0; i < menu; i++) {
			string x;
			getline(cin, x);
			if (x == "pea soup") {
				peasoup = true;
			} else if (x == "pancakes") {
				pancakes = true;
			}
		}
		if (peasoup && pancakes) {
			done = true;
			cout << name << endl;
			break;
		}
	}
	if (!done) {
		cout << "Anywhere is fine I guess" << endl;
	}
}