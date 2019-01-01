#include <bits/stdc++.h>
using namespace std;

int main() {
	int op;
	while (cin >> op, op != 0) {
		string bit = "????????????????????????????????";
		while (op--) {
			string comm;
			int ind, ind2;
			cin >> comm;
			if (comm == "SET" || comm == "CLEAR") {
				cin >> ind;
			}
			else {
				cin >> ind >> ind2;
			}
			int real = 31-ind, real2 = 31-ind2;
			if (comm == "SET") {
				bit[real] = '1';
			}
			else if (comm == "CLEAR") {
				bit[real] = '0';
			}
			else if (comm == "OR") {
				if (bit[real] == '0' && bit[real2] == '0') {
					bit[real] = '0';
				}
				else if ((bit[real] == '1' || bit[real2] == '1')) {
					bit[real] = '1';
				}
				else {
					bit[real] = '?';
				}
			}
			else if (comm == "AND") {
				if (bit[real] == '0' || bit[real2] == '0') {
					bit[real] = '0';
				}
				else if (bit[real] == '1' && bit[real2] == '1') {
					bit[real] = '1';
				}
				else {
					bit[real] = '?';
				}
			}
		}
		cout << bit << endl;
	}
}