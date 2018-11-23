#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
using namespace std;

int main() {
	int h, v, l;
	cin >> h >> v;
	l = h / sin(v * 2 * (M_PI / 360));
	l = floor(l) + 1;
	cout << l << endl;
}