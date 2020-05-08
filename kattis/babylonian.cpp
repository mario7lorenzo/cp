#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		string seg;
		cin >> seg;
		vector<int> saver;
		string temp = "";
		for (int i = 0; i < seg.length(); i++) {
			if (seg[i] == ',') {
				if (temp != "") {
					saver.push_back(stoi(temp));
				}
				else {
					saver.push_back(0);
				}
				temp = "";
			}
			else {
				temp += seg[i];
			}
		}
		if (temp != "") {
			saver.push_back(stoi(temp));
		}
		else {
			saver.push_back(0);
		}
		int pangkat = saver.size()-1;
		long long counter = 0;
		int ind = 0;
		while (ind < saver.size()) {
			counter += saver[ind] * pow(60, pangkat);
			pangkat--;
			ind++;
		}
		cout << counter << endl;
	}
}