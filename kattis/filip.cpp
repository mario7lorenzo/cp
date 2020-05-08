#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	string c, d, e, f;
	c = to_string(a);
	d = to_string(b);
	e = "";
	f = "";
	for (int i = 0; i < 3; i++) {
		e += c.substr(2-i,1);
		f += d.substr(2-i,1);
	}
	int g = stoi(e);
	int h = stoi(f);
	if (g > h) {
		cout << g << endl;
	}
	else {
		cout << h << endl;
	}
}	