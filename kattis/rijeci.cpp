#include <bits/stdc++.h>
using namespace std;

int main() {
	int press;
	cin >> press;
	int a = 1, b = 0;
	for (int i = 0; i < press; i++) {
		int tempa = b;
		int tempb =	a+b;
		a = tempa;
		b = tempb;
	}
	cout << a << ' ' << b << endl;
}