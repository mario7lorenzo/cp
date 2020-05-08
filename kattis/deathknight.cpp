#include <bits/stdc++.h>
using namespace std;

int main() {
	int battle;
	cin >> battle;
	int lose = 0;
	for (int i = 0; i < battle; i++) {
		string op;
		cin >> op;
		for (int j = 0; j < op.length()-1; j++) {
			if (op.substr(j, 2) == "CD") {
				lose++;
			} 
		}
	}
	cout << battle-lose << endl;
}