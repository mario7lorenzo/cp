#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<int> parser(string x) {
	vector<int> saver;
	int len = x.length();
	string temp = "";
	for (int i = 0; i < len; i++) {
		if (x[i] == ' ' && temp != "") {
			int vars;
			if (temp[0] == '~') {
				vars = -(stoi(temp.substr(2, temp.length()-2)));
			} else {
				vars = stoi(temp.substr(1, temp.length()-1));
			}
			saver.push_back(vars);
			temp = "";
		} else if (x[i] == 'v' || x[i] == ' ') {
			continue;
		} else {
			temp += x[i];
		}
	}
	int vars;
	if (temp[0] == '~') {
		vars = -(stoi(temp.substr(2, temp.length()-2)));
	} else {
		vars = stoi(temp.substr(1, temp.length()-1));
	}
	saver.push_back(vars);
	return saver;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int t;
	cin >> t;
	bool isfirst = true;
	while(t--) {
		vector<vector<int>> clauses;
		int m, n;
		cin >> m >> n;
		bool exist = false;
		string stmt;
		getline(cin, stmt);
		for (int i = 0; i < n; i++) {
			getline(cin, stmt);
			vector<int> vi = parser(stmt);
			clauses.push_back(vi);
		}
		for (int i = 0; i <= m; i++) {
			if (exist) {
				break;
			}
			vector<int> bit;
			for (int j = 0; j < m; j++) {
				if (j < i) {
					bit.push_back(1);
				} else {
					bit.push_back(0);
				}
			}
			// for (auto i : bit) {
			// 	cout << i << ' ';
			// }
			// cout << endl;
			bool res = true;
    		for (int i = 0; i < n; i++) {
        		vector<int> clause = clauses[i];
        		bool curr = false;
        		int len = clause.size();
        		for (int j = 0; j < len; j++) {
            		if (clause[j] < 0) {
                		if ((!bit[-clause[j]-1])) {
                			curr = true;
                			break;
                		}
            		} else {
                		if ((bit[clause[j]-1])) {
                			curr = true;
                			break;
                		}
            		}
        		}
        		if (!curr) {
        			res = false;
        			break;
        		}
    		}
    		exist = exist || res;
			while(prev_permutation(bit.begin(), bit.end())) {
				// for (auto i : bit) {
				// 	cout << i << ' ';
				// }
				// cout << endl;
				bool res = true;
        		for (int i = 0; i < n; i++) {
            		vector<int> clause = clauses[i];
            		bool curr = false;
            		int len = clause.size();
            		for (int j = 0; j < len; j++) {
                		if (clause[j] < 0) {
                    		if ((!bit[-clause[j]-1])) {
                    			curr = true;
                    			break;
                    		}
                		} else {
                    		if ((bit[clause[j]-1])) {
                    			curr = true;
                    			break;
                    		}
                		}
            		}
            		if (!curr) {
            			res = false;
            			break;
            		}
        		}
        		exist = exist || res;
			}	
		}

		// for (auto i : bit) {
		// 	cout << i << ' ';
		// }
		if (exist) {
			cout << "satisfiable" << endl;
		} else {
			cout << "unsatisfiable" << endl;
		}
	}
}