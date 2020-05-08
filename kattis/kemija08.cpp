#include <bits/stdc++.h>
using namespace std;

int main() {
	string p;
	getline(cin, p);
	string final = "";
	int i = 0;
	while (i < p.length()) {
		if (p[i] == 'a' || p[i] == 'i' || p[i] == 'u' || p[i] == 'e' || p[i] == 'o') {
			final += p[i];
			i += 3;
		}
		else {
			final += p[i];
			i++;
		}
	}
	cout << final << endl;
}