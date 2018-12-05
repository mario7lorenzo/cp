#include <bits/stdc++.h>
using namespace std;

int main() {
	string name;
	unordered_map<string, int> saver;
	while (getline(cin, name), name != "***") {
		saver[name]++;
	}
	int maxi = -1;
	unordered_map<string, int>::iterator i;
	for (i = saver.begin(); i != saver.end(); i++) {
		maxi = max(maxi, i->second);
	}
	int counter = 0;
	string temp = "";
	for (i = saver.begin(); i != saver.end(); i++) {
		if (i->second == maxi) {
			counter++;
			temp = i->first;
		}
	}
	if (counter == 1) {
		cout << temp << endl;
	}
	else {
		cout << "Runoff!" << endl;
	}
}