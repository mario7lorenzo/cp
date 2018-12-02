#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> tes;
	tes.push_back(a);
	tes.push_back(b);
	tes.push_back(c);
	sort(tes.begin(), tes.end());
	if (tes[1]-tes[0]==tes[2]-tes[1]) {
		cout << tes[2]+tes[1]-tes[0] << endl;
	}
	else if (tes[1]-tes[0] == 2*(tes[2]-tes[1])) {
		cout << tes[0]+tes[2]-tes[1] << endl;
	}
	else if (tes[2]-tes[1] == 2*(tes[1]-tes[0])) {
		cout << tes[1]+(tes[1]-tes[0]) << endl;
	}
}