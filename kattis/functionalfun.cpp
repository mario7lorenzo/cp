#include <bits/stdc++.h>
using namespace std;

int main() {
	string d, c;
	while (getline(cin, d)) {
		getline(cin, c);
		// cout << d << endl;
		// cout << c << endl;
		unordered_map<string, vector<string>> domain, codomain;
		vector<string> saverd, saverc;
		string temp = "";
		for (int i = 7; i < d.length(); i++) {
			if (d[i] == ' ') {
				saverd.push_back(temp);
				temp = "";
			}
			else {
				temp += d[i];
			}
		}
		saverd.push_back(temp);
		temp = "";
		for (int i = 9; i < c.length(); i++) {
			if (c[i] == ' ') {
				// cout << "ini temp " << temp << endl;
				saverc.push_back(temp);
				temp = "";
			}
			else {
				temp += c[i];
			}
		} 
		saverc.push_back(temp);
		int t;
		cin >> t;
		for (int i = 0; i < t; i++) {
			string dom, dumarr, cod;
			cin >> dom >> dumarr >> cod;
			// cout << dom << ' ' << cod << endl;
			domain[dom].push_back(cod);
			codomain[cod].push_back(dom);
		}
		unordered_map<string, vector<string>>::iterator i;
		bool isfunction = true;
		for (i = domain.begin(); i != domain.end(); i++) {
			if (i->second.size() > 1) {
				isfunction = false;
				break;
			}
		}
		if (!isfunction) {
			cout << "not a function" << endl;
		}
		else {
			bool injective = true, surjective = true;
			for (int i = 0; i < saverc.size(); i++) {
				// cout << "ini saverc " << saverc[i] << ' ' << codomain[saverc[i]].size() << endl;  
				if (codomain[saverc[i]].size() == 0) {
					surjective = false;
				}
				else if (codomain[saverc[i]].size() > 1) {
					injective = false;
				}
			}
			if (injective && surjective) {
				cout << "bijective" << endl;
			}
			else if (injective) {
				cout << "injective" << endl;
			}
			else if (surjective) {
				cout << "surjective" << endl;
			}
			else {
				cout << "neither injective nor surjective" << endl;
			}
		}
		cin.ignore();
	}
}