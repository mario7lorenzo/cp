#include <bits/stdc++.h>
using namespace std;


int main() {
	string p;
	while (getline(cin ,p)) {
		vector<int> saver;
		string temp = "";
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == ' ') {
				saver.push_back(stoi(temp));
				temp = "";
			}
			else {
				temp += p[i];
			}
		}
		saver.push_back(stoi(temp));
		int counter = 0;
		for (int i = 0; i < saver.size(); i++) {
			counter += saver[i];
		}
		int num = -1e9;
		for (int i = 0; i < saver.size(); i++) {
			if (counter-saver[i] == saver[i]) {
				num = saver[i];
				break;
			}
		}
		cout << num << endl;
	}
}