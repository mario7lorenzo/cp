#include <bits/stdc++.h>
using namespace std;

bool harshad(long long x) {
	string temp = to_string(x);
	long long counter = 0;
	for (int i = 0; i < temp.length(); i++) {
		counter += stoi(temp.substr(i, 1));
	}
	if (x%counter) {
		return false;
	}
	else {
		return true;
	}
}

int main() {
	long long num;
	cin >> num;
	bool verify = false;
	while (!verify) {
		verify = harshad(num);
		num++;
	}
	cout << num-1 << endl;
}