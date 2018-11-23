#include <bits/stdc++.h>
using namespace std;

int main() {
	int students;
	int commands;
	cin >> students >> commands;
	stack<int> stk;
	stk.push(0);
	for (int i = 0; i < commands; i++) {
		string lempar;
		cin >> lempar;
		if (lempar == "undo") {
			int howmuch;
			cin >> howmuch;
			for (int i = 0; i < howmuch; i++) {
				stk.pop();
			}
		}
		else {
			if (stoi(lempar) < 0) {
				int curr;
				curr = stk.top();
				curr -= (-stoi(lempar))%students;
				if (curr < 0) {
					while (curr < students) {
						curr += students;
					}
				}
				stk.push(curr);
			}
			else {
				int curr;
				curr = stk.top();
				curr += stoi(lempar)%students;
				if (curr >= 5) {
					while (curr >= students) {
						curr -= students;
					}
				}
				stk.push(curr);
			}
		}
	}
	cout << stk.top() << endl;
}