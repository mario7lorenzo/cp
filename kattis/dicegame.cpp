#include <bits/stdc++.h>
using namespace std;

int main() {
	int ag1, bg1, ag2, bg2, ae1, be1, ae2, be2;
	cin >> ag1 >> bg1 >> ag2 >> bg2 >> ae1 >> be1 >> ae2 >> be2;
	if ((ag1+bg1+ag2+bg2) == (ae1+be1+ae2+be2)) {
		cout << "Tie" << endl;
	}
	if ((ag1+bg1+ag2+bg2) < (ae1+be1+ae2+be2)) {
		cout << "Emma" << endl;
	}
	if ((ag1+bg1+ag2+bg2) > (ae1+be1+ae2+be2)) {
		cout << "Gunnar" << endl;
	}
}