#include <bits/stdc++.h>
using namespace std;

int main(void) {
    double k, l, s, w, r, v;
    while (cin >> k >> l >> s >> w) {
	    if ((k == 0.0) && (l == 0.0) && (s == 0.0) && (w == 0.0)) break;
	    if (s-l <= 0.0) {
	        v = 2.0 * 9.81 * s;
	    } 
	    else {
	        v = (2.0*9.81*s) - (k/w)*(s-l)*(s-l);
	    }
	    if (v < 0.0) {
	        cout << "Stuck in the air." << endl;
	    } 
	    else if (v <= 100.00) {
	        cout << "James Bond survives." << endl;
	    } 
	    else {
	        cout << "Killed by the impact." << endl;
	    }
    }
}