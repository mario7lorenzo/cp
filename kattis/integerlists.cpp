#include <bits/stdc++.h>
using namespace std;

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        string op;
        int panjang;
        int poin = 0;
        string lis;
        cin >> op >> panjang >> lis;
        deque<int> lst;
        string ok = "";
        bool note = true;
        for (int j = 0; j < lis.length(); j++) {
            if (lis[j] == '[' || lis[j] == ']') {
                continue;
            }
            if (lis[j] == ',') {
            	lst.push_back(stoi(ok));
            	ok = "";
            }
            else {
            	ok += lis.substr(j,1);
            }
        }
        if (ok != "") {
        	lst.push_back(stoi(ok));
            }
       	for (int k = 0; k < op.length(); k++) {
            if (op.substr(k, 1) == "R") {
                if (poin == 1) {
                	poin = 0;
                }
                else {
                	poin = 1;
                }
            }
            else {
            	if (lst.size() != 0) {
                	if (poin == 1) {
                    	lst.pop_back();
                	}
                	else {
                    	lst.pop_front();
                	}
                }
                else {
                	note = false;
                	cout << "error" << endl;
                	break;
                }
            }
        }
        if (lst.size() != 0) {
            if (poin == 1) {
            	cout << '[';
            	for (int l = lst.size()-1; l >= 0; l--) {
                	if (l == 0) {
                    	cout << lst[0] << ']' << endl;
                	}
                	else {
                    	cout << lst[l] << ',';
                	}
            	}
            }
            else {
            	cout << '[';
            	for (int l = 0; l < lst.size(); l++) {
                	if (l == lst.size()-1) {
                    	cout << lst[lst.size()-1] << ']' << endl;
                	}
                	else {
                    	cout << lst[l] << ',';
                	}
            	}
            }
       	}
       	else if (note) {
       		cout << "[]" << endl;
       	}
    }
}