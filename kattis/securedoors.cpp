#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_set<string> name;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string op, nama;
		cin >> op >> nama;
		if (op == "entry") {
			cout << nama << " entered";
			if (name.find(nama) != name.end()) {
				cout << " (ANOMALY)";
			}
			name.insert(nama);
			cout << endl;
		}
		else if (op == "exit") {
			cout << nama << " exited";
			if (name.find(nama) == name.end()) {
				cout << " (ANOMALY)";
			}
			else {
				name.erase(nama);
			}
			cout << endl;
		}
	}
}