#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int seq, n;
    cin >> seq >> n;
    vector<int> num;
    map<int, int> leftodd, lefteven, rightodd, righteven;
    int piv;
    int diff[100010];
    for (int i = 0; i < seq; i++) {
    	int x;
    	cin >> x;
    	if (n == x) {
    		piv = i;
    	}
    	num.push_back(x);
    }
    int curr = 0;
    for (int i = piv + 1; i < seq; i++) {
    	if (num[i] < n) {
    		curr--;
    	}
    	else {
    		curr++;
    	}
    	diff[i] = curr;
    	// cout << i << ' ' << curr << endl;
    }
    curr = 0;
   	for (int i = piv - 1; i >= 0; i--) {
   		if (num[i] < n) {
   			curr--;
   		}
   		else {
   			curr++;
   		}
   		diff[i] = curr;
   		// cout << i << ' ' << curr << endl;
   	}
   	int tot = 1;
   	for (int i = 0; i < piv; i++) {
   		if (i%2) {
   			leftodd[diff[i]]++;
   		}
   		else {
   			lefteven[diff[i]]++;
   		}
   	}
   	for (int i = piv+1; i < seq; i++) {
   		if (i%2) {
   			rightodd[diff[i]]++;
   		}
   		else {
   			righteven[diff[i]]++;
   		}
   	}
   	int nolkigan = leftodd[0], nolkinap = lefteven[0], nolkagan = rightodd[0], nolkanap = righteven[0];
   	tot += nolkagan + nolkigan + (nolkigan * nolkagan) + nolkinap + nolkanap + (nolkanap * nolkinap);
   	map<int, int>::iterator it;
   	for (it = leftodd.begin(); it != leftodd.end(); it++) {
   		int dif = it->first;
   		if (dif == 0) {
   			continue;
   		}
   		tot += it->second * rightodd[-dif];
   	}
   	for (it = lefteven.begin(); it != lefteven.end(); it++) {
   		int dif = it->first;
   		if (dif == 0) {
   			continue;
   		}
   		tot += it->second * righteven[-dif];
   	}
   	cout << tot << endl;
}