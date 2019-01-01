#include <bits/stdc++.h>
using namespace std;

int main() {
	string p;
	while (getline(cin, p)) {
		vector<string> lst;
		bool awal;
		if (int(p[0]) >= 49 && int(p[0]) <= 57) {
			awal = false;
		}
		else {
			awal = true;
		}
		string temp = "";
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == ' ') {
				lst.push_back(temp);
				temp = "";
			} 
			else {
				temp += p[i];
			}
		}
		lst.push_back(temp);
		if (awal) {
			int border;
			string name = "";
			bool isfirst = true;
			for (int i = 0; i < lst.size(); i++) {
				if (int(lst[i][0]) >= 49 && int(lst[i][0]) <= 57) {
					border = i;
					break;
				}
				else {
					if (isfirst) {
						name += lst[i];
						isfirst = false;
					}
					else {
						name += ' ';
						name += lst[i];
					}
				}
			}
			int counter = 0;
			double tot = 0.0;
			for (int i = border; i < lst.size(); i++) {
				tot += stod(lst[i]);
				counter++;
			}
			cout << fixed << setprecision(5) << tot/double(counter) << ' ' << name << endl;
		}
		else {
			string name = "";
			int border;
			bool isfirst = true;
			for (int i = lst.size()-1; i >= 0; i--) {
				if (int(lst[i][0]) >= 49 && int(lst[i][0]) <= 57) {
					border = i;
					break;
				}
				else {
					if (isfirst) {
						name += lst[i];
						isfirst = false;
					}
					else {
						name = lst[i] + ' ' + name;
					}
				}
			}
			int counter = 0;
			double tot = 0.0;
			for (int i = 0; i <= border; i++) {
				tot += stod(lst[i]);
				counter++;
			}
			cout << fixed << setprecision(5) << tot/double(counter) << ' ' << name << endl;			
		}
	}
}