#include <bits/stdc++.h>
using namespace std;

int main() {
	string mth;
	int dt;
	cin >> mth;
	cin >> dt;
	if ((mth == "OCT" && dt == 31) || (mth == "DEC" && dt == 25)) {
		cout << "yup" << endl;
	}
	else {
		cout << "nope" << endl;
	}
}