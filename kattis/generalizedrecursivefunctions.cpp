#include <bits/stdc++.h>
using namespace std;

vector<int> saver;
vector<int> op;

long long genrec(int x, int y) {
	int c = saver[saver.size()-2];
	int d = saver[saver.size()-1];
	if (x <= 0 || y <= 0) {
		return d;
	}
	else {
		long long counter = c;
		int pasang = (saver.size()-2);
		for (int i = 1; i < pasang; i+=2) {
			int a, b;
			a = saver[i-1];
			b = saver[i];
			counter += genrec(x-a, y-b);
		}
		return counter;
	}
}

int main() {
	int testcase;
	cin >> testcase;
	bool isfirst = true;
	for (int i = 0; i < testcase; i++) {
		string p;
		if (isfirst) {
			cin.ignore();
			isfirst = false;
		}
		getline(cin, p);
		string temp = "";
		for (int j = 0; j < p.length(); j++) {
			if (p[j] == ' ') {
				saver.push_back(stoi(temp));
				temp = "";
			}
			else {
				temp += p[j];
			}
		}
		saver.push_back(stoi(temp));
		// for (int i = 0; i < saver.size(); i++) {
		// 	cout << "ini saver " << saver[i] << endl; 
		// }
		string t;
		getline(cin, t);
		// cout << t << endl;
		temp = "";
		for (int j = 0; j < t.length(); j++) {
			if (t[j] == ' ') {
				op.push_back(stoi(temp));
				temp = "";
			}
			else {
				temp += t[j];
			}
		}
		op.push_back(stoi(temp));
		for (int i = 1; i < op.size(); i+=2) {
			int x, y;
			x = op[i-1];
			y = op[i];
			cout << genrec(x, y) << endl;
		}
		cout << endl;
		saver.clear();
	}
}