#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	string p;
	while (getline(cin, p)) {
		vector<int> ruler;
		string tmp = "";
		for (auto i : p) {
			if (i == ' ') {
				ruler.push_back(stoi(tmp));
				tmp = "";
			}
			else {
				tmp += i;
			}
		}
		ruler.push_back(stoi(tmp));
		bool norul = false;
		unordered_map<int, bool> saver;
		for (int i = 1; i <= 2000; i++) {
			saver[i] = false;
		}
		int maxi = -1;
		for (int i = 1; i < ruler.size(); i++) {
			for (int j = 0; j < i; j++) {
				int me = abs(ruler[j]-ruler[i]);
				if (saver[me]) {
					norul = true;
					break;
				}
				else {
					maxi = max(maxi, me);
					saver[me] = true;
				}
			}
		}
		if (norul) {
			cout << "not a ruler" << endl;
		}
		else {
			vector<int> lst;
			for (int i = 1; i <= maxi; i++) {
				if (!saver[i]) {
					lst.push_back(i);
				}
			}
			if (lst.size() == 0) {
				cout << "perfect" << endl;
			}
			else {
				cout << "missing";
				for (auto i : lst) {
					cout << ' ' << i;
				}
				cout << endl;
			}
		}
	}
}