#include <bits/stdc++.h>
using namespace std;

int main() {
	double n;
	cin >> n;
	double p = 1/n;
	cout << fixed << setprecision(10) << pow(n, p) << endl;
}