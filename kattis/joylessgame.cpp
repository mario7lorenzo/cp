#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		string word;
		cin >> word;
		vector<char> lst;
		for (int j = 0; j < word.length(); j++) {
			lst.push_back(word[j]);
		}
		bool turn = true;
		int counter = 0;
		while (lst.size() > 2) {
			bool change = false;
			for (int j = 1; j < lst.size()-1; j++) {
				if (lst[j-1] != lst[j+1]) {
					lst.erase(lst.begin()+j);
					turn = !turn;
					change = true;
					break;
					counter++;
				}
			}
			if (!change) {
				break;
			}
		}
		if (turn) {
			cout << "Bash" << endl;
		}
		else {
			cout << "Chikapu" << endl;
		}
	}
}