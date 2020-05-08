#include <bits/stdc++.h>
using namespace std;

unordered_map<char, long long> occ;
unordered_map<char, long long> req;
string mol, create;
int many;

void helper1() {
	bool cond = true, isfirst = true;
	char curr;
	string amount = "";
	for (auto i : mol) {
		if (isfirst) {
			curr = i;
			isfirst = false;
		}
		else if (int(i) >= 65 && int (i) <= 90) {
			if (cond) {
				occ[curr]++;
			}
			else {
				occ[curr] += stoll(amount);
			}
			// cout << occ[curr] << ' ' << curr << endl;
			curr = i;
			cond = true;
			amount = "";
		}
		else {
			amount += i;
			cond = false;
		}	
	}
	if (cond) {
		occ[curr]++;
	}
	else {
		occ[curr] += stoll(amount);
	}
	// cout << occ[curr] << ' ' << curr << endl;
	unordered_map<char, long long>::iterator it;
	for (it = occ.begin(); it != occ.end(); it++) {
		occ[it->first] = many*(it->second);
	}
}

void helper2() {
	bool cond = true, isfirst = true;
	char curr;
	string amount = "";
	for (auto i : create) {
		if (isfirst) {
			curr = i;
			isfirst = false;
		}
		else if (int(i) >= 65 && int (i) <= 90) {
			if (cond) {
				req[curr]++;
			}
			else {
				req[curr] += stoll(amount);
			}
			curr = i;
			cond = true;
			amount = "";
		}
		else {
			amount += i;
			cond = false;
		}	
	}
	if (cond) {
		req[curr]++;
	}
	else {
		req[curr] += stoll(amount);
	}	
}

int main() {
	cin >> mol >> many >> create;
	helper1();
	helper2();
	unordered_map<char, long long>::iterator it;
	long long mini = 1e9;
	for (it = req.begin(); it != req.end(); it++) {
		char tmp = it->first;
		long long tmp2 = it->second;
		// cout << tmp << ' ' << tmp2 << ' ' << occ[tmp] <<  endl;
		long long fin = occ[tmp]/tmp2;
		mini = min(mini, fin);
	}
	cout << mini << endl;
}