#include <bits/stdc++.h>
using namespace std;

int onebincov(string x) {
	long long num = stoll(x);
	string bin = "";
	while (num > 0) {
		bin += to_string(num%2);
		num /= 2;
	}
	reverse(bin.begin(), bin.end());
	int counter = 0;
	for (int i = 0; i < bin.length(); i++) {
		if (bin[i] == '1') {
			counter++;
		}
	}
	return counter;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string num;
		cin >> num;
		string temp = "";
		int maxi = -1;
		for (int i = 0; i < num.length(); i++) {
			temp += num[i];
			maxi = max(maxi, onebincov(temp));
		}
		cout << maxi << endl;
	}
}