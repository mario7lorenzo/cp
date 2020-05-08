#include <bits/stdc++.h>
using namespace std;

int main() {
	int mininf = -1e9;
	string a, b;
	cin >> a >> b;
	int maxi = max(a.length(), b.length());
	vector<int> af;
	vector<int> bf;
	for (int i = 0; i < maxi; i++) {
		if (i < (maxi-a.length())) {
			af.push_back(-1);
		}
		else {
			af.push_back(stoi(a.substr(i-maxi+a.length(),1)));
		}
	}
	for (int i = 0; i < maxi; i++) {
		if (i < (maxi-b.length())) {
			bf.push_back(-1);
		}
		else {
			bf.push_back(stoi(b.substr(i-maxi+b.length(),1)));
		}
	}
	for (int i = 0; i < maxi; i++) {
		if (af[i] < bf[i]) {
			af[i] = mininf;
		}
		else if (af[i] > bf[i]) {
			bf[i] = mininf;
		}
	}
	bool minsatu = true;
	for (int i = 0; i < af.size(); i++) {
		if (af[i] != mininf) {
			minsatu = false;
		} 
	}
	if (minsatu) {
		cout << "YODA" << endl;
	}
	else {
		string afinal = "";
		for (int i = 0; i < af.size(); i++) {
			if (af[i] != mininf) {
				afinal += to_string(af[i]);
			}
		}
		cout << stoi(afinal) << endl;
	}
	minsatu = true;
	for (int i = 0; i < bf.size(); i++) {
		if (bf[i] != mininf) {
			minsatu = false;
		} 
	}
	if (minsatu) {
		cout << "YODA" << endl;
	}
	else {
		string bfinal = "";
		for (int i = 0; i < bf.size(); i++) {
			if (bf[i] != mininf) {
				bfinal += to_string(bf[i]);
			}
		}
		cout << stoi(bfinal) << endl;
	}
}