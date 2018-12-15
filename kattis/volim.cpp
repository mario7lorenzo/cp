#include <bits/stdc++.h>
using namespace std;

int main() {
	int init, tm = 210, final, questions, durr = 0;
	cin >> init;
	init--;
	queue<int> tbl;
	for (int i = 0; i < 8; i++) {
		tbl.push(init%8);
		init++;
	}
	cin >> questions;
	for (int i = 0; i < questions; i++) {
		int dur;
		char stat;
		cin >> dur >> stat;
		durr += dur;
		if (durr >= tm) {
			cout << tbl.front() + 1 << endl;
			break;
		}
		else if (stat == 'T') {
			int temp = tbl.front();
			tbl.pop();
			tbl.push(temp);
		}
	}
}