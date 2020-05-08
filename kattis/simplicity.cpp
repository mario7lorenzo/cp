#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<char, int> saver;
	string x;
	cin >> x;
	for (auto i : x) {
		saver[i]++;
	}
	int simplicity = saver.size();
	if (simplicity <= 2) {
		cout << 0 << endl;
	}
	else {
		unordered_map<char, int>::iterator i;
		map<int, vector<char>> otto;
		for (i = saver.begin(); i != saver.end(); i++) {
			otto[i->second].push_back(i->first);
		}
		map<int, vector<char>>::iterator itr;
		int kurang = simplicity-2, counter = 0;
		for (itr = otto.begin(); itr != otto.end(); itr++) {
			vector<char> temp = itr->second;
			int bentar = temp.size();
			counter += (itr->first)*(min(kurang, bentar));
			if (kurang <= itr->second.size()) {
				break;
			}
			else {
				kurang -= itr->second.size();
			}
		}
		cout << counter << endl;
	}
}