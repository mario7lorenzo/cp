#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	string kids;
	cin >> kids;
	int currpiv = kids.length()-1;
	long long swap = 0;
	vector<int> dua, satu;
	string round2 = "";
	for (int i = 0; i < kids.length(); i++) {
		if (kids[i] == '2') {
			dua.push_back(i);
		}
		else {
			round2 += kids[i];
		}
	}
	for (int i = dua.size()-1; i >= 0; i--) {
		swap += currpiv - dua[i];
		currpiv--;
	}
	for (int i = 0; i < round2.length(); i++) {
		if (round2[i] == '1') {
			satu.push_back(i);
		}
	}
	for (int i = satu.size()-1; i >= 0; i--) {
		swap += currpiv - satu[i];
		currpiv--;
	}
	cout << swap << endl;
}