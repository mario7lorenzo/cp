#include <bits/stdc++.h>
using namespace std;

int main() {
	string p;
	unordered_map<string, int> saver;
	while (getline(cin, p)) {
		if (p.substr(0, 6) == "define") {
			int val;
			string temp = "";
			for (int i = 7; i < p.length(); i++) {
				if (p[i] == ' ') {
					val = stoi(temp);
					temp = "";
				}
				else {
					temp += p[i];
				}
			}
			saver[temp] = val;
		}
		else if (p.substr(0, 4) == "eval") {
			string com1, com2, op;
			string temp = "";
			bool isfirst = true;
			for (int i = 5; i < p.length(); i++) {
				if (p[i] == ' ') {
					if (isfirst) {
						com1 = temp;
						isfirst = false;
						temp = "";
					}
					else {
						op = temp;
						temp = "";
					}
				}
				else {
					temp += p[i];
				}
			}
			com2 = temp;
			if (saver.find(com1) == saver.end() || saver.find(com2) == saver.end()) {
				cout << "undefined" << endl;
			}
			else {
				if (op == "=") {
					if (saver[com1] == saver[com2]) {
						cout << "true" << endl;
					}
					else {
						cout << "false" << endl;
					}
				}
				if (op == "<") {
					if (saver[com1] < saver[com2]) {
						cout << "true" << endl;
					}
					else {
						cout << "false" << endl;
					}
				}
				if (op == ">") {
					if (saver[com1] > saver[com2]) {
						cout << "true" << endl;
					}
					else {
						cout << "false" << endl;
					}
				}
			}
		}
	}
}