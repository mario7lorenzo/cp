#include<bits/stdc++.h>
using namespace std;

int main() {
	string digits;
	cin >> digits;

	while (digits != "END") {
		int seqno = 0;

		while (digits != "1") {
			int no = digits.length();
			digits = to_string(no);
			seqno++;
		}

		cout << seqno+1<< endl;
		cin >> digits;
	}
}