#include <bits/stdc++.h>
using namespace std;

int digitsum(int n) {
	string temp = to_string(n);
	int final = 0;
	for (int i = 0; i < temp.length(); i++) {
		string tempo = temp.substr(i, 1);
		final += stoi(tempo);
	}
	return final;
}

int main(){
	int n;
	while (cin >> n, n!=0) {
		int sump = digitsum(n);
		int start = 11;
		int final = -99;
		while (final != sump) {
			int temp = n*start;
			final = digitsum(temp);
			start++;
		}
		cout << start-1 << endl;
	}
}