#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'

vector<pair<int, string>> lstcomm;

int bs(int x, int lb, int ub) {
	int avg = (lb+ub)/2;
	// cout << "ini avg " << avg << ' ' << lstcomm[avg].first << endl;
	if (lstcomm[avg].first == x) {
		return avg;
	}
	else if (lstcomm[avg].first > x) {
		return bs(x, lb, avg-1);
	}
	else {
		return bs(x, avg+1, ub);
	}
}

bool checker(int x, string op, int y) {
	if (op == "=") {
		return (x == y) ? true : false;
	}
	if (op == ">") {
		return (x > y) ? true : false;
	}
	if (op == "<") {
		return (x < y) ? true : false;
	}
	if (op == "<>") {
		return (x != y) ? true : false;
	}
	if (op == ">=") {
		return (x >= y) ? true : false;
	}
	if (op == "<=") {
		return (x <= y) ? true : false;
	}
}



int main() {
	unordered_map<char, int> varsaver;
	for (int i = 0; i < 26; i++) {
		varsaver['A'+i] = 0;
	}
	string p;
	int counter = 0;
	while (getline(cin, p)) {
		int token;
		string temp = "";
		bool can = true;
		for (ll i = 0; i < p.length(); i++) {
			if (p[i] == ' ' && can) {
				can = false;
				token = stoi(temp);
				temp = "";
			}
			else {
				temp += p[i];
			}
		}
		lstcomm.emplace_back(token, temp);
		counter++;
	}
	sort(lstcomm.begin(), lstcomm.end());
	int curr = 0;
	while (curr < counter) {
		// cout << "ini curr " << curr << endl;
		string comm = lstcomm[curr].second;
		// cout << "ini curr " << curr << ' ' << tok << ' ' << comm << endl;
		// cout << comm.substr(0,3) << ' ' << comm.substr(0,2) << ' '<< comm.substr(0,5) << ' ' << comm.substr(0, 7) << endl;
		if (comm.substr(0, 3) == "LET") {
			char var = comm[4];
			string x = "", op = "", y = "";
			bool alt = false;
			bool yyy = false;
			for (ll i = 8; i < comm.length(); i++) {
				if (!alt) {
					if (comm[i] == ' ') {
						alt = true;
					}
					else {
						x += comm[i];
					}
				}
				else {
					if (comm[i] == ' ') {
						yyy = true;
					}
					else if (yyy) {
						y += comm[i];
					}
					else {
						op += comm[i];
					}
				}
			}
			int tot;
			if ((int(x[0]) >= 65 && int(x[0]) <= 90)) {
				tot = varsaver[x[0]];
			}
			else {
				tot = stoi(x);
			}
			if (op != "") {
				if (op == "+") {
					if ((int(y[0]) >= 65 && int(y[0]) <= 90)) {
						tot += varsaver[y[0]];
					}
					else {
						tot += stoi(y);
					}
				}
				if (op == "-") {
					if ((int(y[0]) >= 65 && int(y[0]) <= 90)) {
						tot -= varsaver[y[0]];
					}
					else {
						tot -= stoi(y);
					}
				}
				if (op == "*") {
					if ((int(y[0]) >= 65 && int(y[0]) <= 90)) {
						tot *= varsaver[y[0]];
					}
					else {
						tot *= stoi(y);
					}
				}
				if (op == "/") {
					if ((int(y[0]) >= 65 && int(y[0]) <= 90)) {
						tot /= varsaver[y[0]];
					}
					else {
						tot /= stoi(y);
					}
				}
			}
			varsaver[var] = tot;
			// cout << "ini varsaver " << varsaver[var] << endl;
			curr++;
		}
		else if (comm.substr(0, 2) == "IF") {
			string x = "", op = "", y = "", ind = "";
			int lx, ly, piv;
			bool alt = false, yyy = false;
			for (ll i = 3; i < comm.length(); i++) {
				if (!alt) {
					if (comm[i] == ' ') {
						alt = true;
					}
					else {
						x += comm[i];
					}
				}
				else {
					if (!yyy) {
						if (comm[i] == ' ') {
							yyy = true;
						}
						else {
							op += comm[i];
						}
					}
					else {
						if (comm[i] == ' ') {
							piv = i;
							break;
						}
						else {
							y += comm[i];
						}
					}
				}
			}
			if ((int(x[0]) <= 90 && int(x[0]) >= 65)) {
				lx = varsaver[x[0]];
			}
			else {
				lx = stoi(x);
			}
			if ((int(y[0]) <= 90 && int(y[0]) >= 65)) {
				ly = varsaver[y[0]];
			}
			else {
				ly = stoi(y);
			}
			bool res = checker(lx, op, ly);
			// cout << "Ini res " << res << endl;
			if (res) {
				piv += 11;
				for (ll i = piv; i < comm.length(); i++) {
					ind += comm[i];
				}
				curr = bs(stoi(ind), 0, counter);
			}
			else {
				curr++;
			}
		}
		else if (comm.substr(0, 7) == "PRINTLN") {
			if (comm[8] == '"') {
				for (int i = 9; i < comm.length()-1; i++) {
					cout << comm[i];
				}
			}
			else {
				cout << varsaver[comm[8]];
			}
			cout << endl;
			curr++;
		}
		else if (comm.substr(0, 5) == "PRINT") {
			if (comm[6] == '"') {
				for (int i = 7; i < comm.length()-1; i++) {
					cout << comm[i];
				}
			}
			else {
				cout << varsaver[comm[6]];
			}
			curr++;
		}
	}
}