#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, c;
    cin >> n >> c;
    ll arr[n];
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        arr[i] = x;
    }
    ll l = 0, r = 0;
    ll counterc = arr[0], countern = 0;
    ll len = 0;
    for (int i = 0; i < n; i++) {
    	ll counter = 0, templength = 0;
    	for (int j = i; j < n; j++) {
    		if (counter + arr[j] <= c) {
    			counter += arr[j];
    			templength++;
    		}
    		else {
    			continue;
    		}
    	}
    	len = max(len, templength);
    }
    cout << len << endl;
}
