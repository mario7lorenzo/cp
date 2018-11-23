#include <bits/stdc++.h>
using namespace std;

int main() {
	int num;
	cin >> num;
	string stat = "makes sense";
	for (int i = 0; i < num; i++) {
		string x;
		cin >> x;
		if (x == "mumble") {
			continue;
		}
		else if (i + 1 != stoi(x)) {
			stat = "something is fishy";
			break;
		}
	}
	cout << stat << endl;
}