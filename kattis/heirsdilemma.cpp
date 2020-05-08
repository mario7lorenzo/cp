#include <bits/stdc++.h>
using namespace std;

bool checker(string x) {
	unordered_set<char> saver;
	for (int i = 0; i < x.length(); i++) {
		if (saver.find(x[i]) != saver.end()) {
			return false;
		}
		else {
			saver.insert(x[i]);
		}
	}
	return true;
}

bool checker2(string x) {
	for (int i = 0; i < x.length(); i++) {
		if (x[i] == '0') {
			return false;
		}
		if (stoll(x)%stoll(x.substr(i, 1)) != 0) {
			return false;
		}
	}
	return true;
}

int main() {
	long long counter = 0;
	long long lower, upper;
	cin >> lower >> upper;
	for (int i = lower; i <= upper; i++) {
		if (checker(to_string(i)) && checker2(to_string(i))) {
			counter++;
		}
	}
	cout << counter << endl;
}