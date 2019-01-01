#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_set<int> xax, yax, mindi, plusdi;
	int n;
	cin >> n;
	bool correct = true;
	while (n--) {
		int x, y;
		cin >> x >> y;
		// cout << "ini x " << x << endl;
		// cout << "ini y " << y << endl;
		// cout << "ini mindi " << x+y << endl;
		// cout << "ini plusdi " << y-x << endl;
		if ((xax.find(x) == xax.end()) && (yax.find(y) == yax.end()) && mindi.find(x+y) == mindi.end() && plusdi.find(y-x) == plusdi.end()) {
			xax.insert(x);
			yax.insert(y);
			plusdi.insert(y-x);
			mindi.insert(x+y);
		}
		else {
			correct = false;
			break;
		}
	}
	if (!correct) {
		cout << "INCORRECT" << endl;
	}
	else {
		cout << "CORRECT" << endl;
	}
}