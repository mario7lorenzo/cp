#include <bits/stdc++.h>
using namespace std;

int main() {
	char op;
	cin >> op;
	string p;
	cin >> p;
	if (op == 'E') {
		stack<char> saver;
		char currchar = p[0];
		saver.push(currchar);
		string final = "";
		for (int i = 1; i < p.length(); i++) {
			if (p[i] == currchar) {
				saver.push(p[i]);
			}
			else {
				int counter = 0;
				char temp = saver.top();
				while (!saver.empty()) {
					saver.pop();
					counter++;
				}
				final += temp + to_string(counter);
				currchar = p[i];
				saver.push(p[i]);
			}
		}
		int counter = 0;
		char temp = saver.top();
		while (!saver.empty()) {
			saver.pop();
			counter++;
		}
		final += temp + to_string(counter);
		cout << final << endl;
	}
	else if (op == 'D') {
		string final = "";
		for (int i = 0; i < p.length(); i+=2) {
			char let = p[i];
			int many = stoi(p.substr(i+1, 1));
			while (many > 0) {
				final += let;
				many--;
			}
		}
		cout << final << endl;
	}
}