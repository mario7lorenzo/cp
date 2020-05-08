#include <bits/stdc++.h>
using namespace std;

int main() {
	int p, t;
	cin >> p >> t;
	int solved = 0;
	for (int i = 0; i < p; i++) {
		int subtask = 0;
		for (int j = 0; j < t; j++) {
			string problem;
			cin >> problem;
			bool bener = true;
			for (int k = 0; k < problem.length(); k++) {
				if (k == 0) {
					continue;
				}
				else {
					if (int(problem[k]) < 97) {
						bener = false;
					}
				}
			}
			if (bener) {
				subtask++;
			}
		}
		if (subtask == t) {
			solved++;
		}
	}
	cout << solved << endl;
}