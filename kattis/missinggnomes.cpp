#include <bits/stdc++.h>
using namespace std;

int main() {
    int exp, act;
    cin >> exp >> act;
    vector<int> curr;
    unordered_set<int> saver;
    vector<int> miss;
    for (int i = 0; i < act; i++) {
        int x;
        cin >> x;
        saver.insert(x);
        curr.push_back(x);
    }
    for (int i = 1; i <= exp; i++) {
        if (saver.find(i) == saver.end()) {
            miss.push_back(i);
        }
    }
    int pointer = 0;
    if (miss.size() == 0) {
        for (int i = 0; i < curr.size(); i++) {
            cout << curr[i] << endl;
        }       
    }
    else {
        for (int i = 0; i < curr.size(); i++) {
 			if (pointer < miss.size()) {
	            while (miss[pointer] < curr[i]) {
	                cout << miss[pointer] << endl;
	                pointer++;
	                if (pointer >= miss.size()) {
	                    break;
	                }
	            } 				
 			}
            cout << curr[i] << endl;
        }
        for (int i = pointer; i < miss.size(); i++) {
            cout << miss[i] << endl;
        }       
    }
}