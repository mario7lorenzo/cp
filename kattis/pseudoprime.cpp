#include <bits/stdc++.h>owmod(a, e-1); 
	}
	else {
		return fastpowmod((a*a)%p, e/2);
	}
}

int main() {
	while (cin >> p >> a, a != 0 && p != 0) {
		ll e = p;
		if (p == 2 || p == 3 || (p-1)%6 == 0 || (p+1)%6 == 0) {
			cout << "no" << endl;
		}
		// cout << fastpowmod(a, e) << endl;
		else if (fastpowmod(a, e)%p != a) {
			cout << "no" << endl;
		}
		else {
			cout << "yes" << endl;
		}
	}
}