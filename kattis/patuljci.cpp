#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> dwarf;
	int total = 0;
	for (int i = 0; i < 9; i++) {
		int x;
		cin >> x;
		dwarf.push_back(x);
		total += x;
	}
	total -= 100;
	for (int i = 0; i < 9; i++) {
		bool finish = false;
		for (int j = 0; j < 9; j++) {
			if (i != j) {
				if (dwarf[i] + dwarf[j] == total) {
					dwarf.erase(dwarf.begin()+i);
					if (i < j) {
						dwarf.erase(dwarf.begin()+j-1);
						finish = true;
						break;
					}
					else {
						dwarf.erase(dwarf.begin()+j);
						finish = true;
						break;
					}
				}
			}
		}
		if (finish) {
			break;
		}
	}
	for (int i = 0; i < 7; i++) {
		cout << dwarf[i] << endl;
	}
}