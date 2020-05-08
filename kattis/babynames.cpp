#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

int main() {
	int x;
	ordered_set o_set_all;
	ordered_set o_set_male;
	ordered_set o_set_female;

	while(cin >> x) {
		if (x == 0) {
			break;
		} else if (x == 1) {
			string name;
			cin >> name;
			int gender;
			cin >> gender;
			o_set_all.insert(name);
			if (gender == 1) {
				o_set_male.insert(name);
			} else {
				o_set_female.insert(name);
			}
		} else if (x == 2) {
			string name;
			cin >> name;
			o_set_all.erase(name);
			o_set_male.erase(name);
			o_set_female.erase(name);
		} else {
			string start, end;
			cin >> start >> end;
			int gender;
			cin >> gender;

			if (gender == 0) {
				int tot = o_set_all.find_by_order(end) - o_set_all.find_by_order(start);
				if (o_set_all.find(start) != o_set_all.end()) {
					cout << tot + 1 << endl;
				} else {
					cout << tot << endl;
				}
			} else if (gender == 1) {
				int tot = o_set_male.find_by_order(end) - o_set_male.find_by_order(start);
				if (o_set_male.find(start) != o_set_male.end()) {
					cout << tot + 1 << endl;
				} else {
					cout << tot << endl;
				}
			} else {
				int tot = o_set_female.find_by_order(end) - o_set_female.find_by_order(start);
				if (o_set_female.find(start) != o_set_female.end()) {
					cout << tot + 1 << endl;
				} else {
					cout << tot << endl;
				}
			}
		}
	}
}