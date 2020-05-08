#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>> al, inval;
unordered_map<string, bool> isvisited, invisvisited;
vector<string> toposort, invtoposort;


void dfs(string node) {
	isvisited[node] = true;
	for (auto neigh : al[node]) {
		if (!isvisited[neigh]) {
			dfs(neigh);
		}
	}
	toposort.push_back(node);
}


int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string makefile;
    getline(cin, makefile);
    for (int i = 0; i < n; i++) {
		getline(cin, makefile);
    	string file = "";
    	string deps = "";
    	bool isfile = true;
    	for (auto i : makefile) {
    		if (i == ':') {
    			isvisited[file] = false;
    			invisvisited[file] = false;
    			isfile = false;
    		} else if (i == ' ') {
    			if (deps != "") {
    				al[deps].push_back(file);
    				inval[file].push_back(deps);
    				deps = "";
    			}
    		} else if (isfile) {
    			file += i;
    		} else {
    			deps += i;
    		}
    	}
    	if (deps != "") {
			al[deps].push_back(file);
			inval[file].push_back(deps);
			deps = "";
		}
    }
    string changed;
    cin >> changed;
    dfs(changed);
    
    for (int i = 1; i < toposort.size(); i++) {
    	cout << toposort[i] << endl;
    }
}