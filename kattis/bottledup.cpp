#include <bits/stdc++.h>
using namespace std;

int main() {
	long long s, v1, v2;
	cin >> s >> v1 >> v2;
	long long mini = 1e9, satu = 0, dua = 0;
	long long kecil = min(v1,v2); 
	for (int i = 0; i <= (s/v1)+1; i++) {
		if ((s - (i*v1))%v2 == 0 && (s - (i*v1)) >= 0) {
			if (mini > (i + (s - (i*v1))/v2)) {
				mini = i + (s - (i*v1))/v2;
				satu = i;
				dua = (s - (i*v1))/v2;
			}
		}
	}
	if (mini == 1e9) {
		cout << "impossible" << endl;
	}
	else {
		cout << satu << ' ' << dua << endl;
	}
}