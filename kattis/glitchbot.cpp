#include <bits/stdc++.h>
using namespace std;
int currx = 0, curry = 0, dir = 0;
string movement;

void op() {
	if (movement == "Forward") {
		if (dir == 0) {
			curry++;
		}
		if (dir == 1) {
			currx++;
		}
		if (dir == 2) {
			curry--;
		}
		if (dir == 3) {
			currx--;
		}
	}
	else if (movement == "Left") {
		dir--;
		if (dir < 0) {
			dir = 3;
		}
	}
	else if (movement == "Right") {
		dir++;
		dir%=4;
	}
}

int main() {
	int x, y, command;
	cin >> x >> y >> command;
	vector<string> lst;
	for (int i = 0; i < command; i++) {
		string per;
		cin >> per;
		lst.push_back(per);
	}
	vector<string> cop = lst;
	for (int i = 0; i < command; i++) {
		string bentar = cop[i];
		// cout << "========================" << endl;
		// cout << "ini i " << i << endl;
		cop[i] = "Forward";
		for (int j = 0; j < command; j++) {
			movement = cop[j];
			op();
		}
		// cout << "ini kl for " << currx << ' ' << curry << endl;
		if (currx == x && curry == y) {
			cout << i+1 << " Forward" << endl;
			break;
		}
		currx = 0;
		curry = 0;
		dir = 0;
		cop[i] = "Left";
		for (int j = 0; j < command; j++) {
			movement = cop[j];
			op();
		}
		if (currx == x && curry == y) {
			cout << i+1 << " Left" << endl;
			break;
		}
		// cout << "ini kl left " << currx << ' ' << curry << endl;
		currx = 0;
		curry = 0;
		dir = 0;
		cop[i] = "Right";
		for (int j = 0; j < command; j++) {
			movement = cop[j];
			op();
		}
		// cout << "ini kl right " << currx << ' ' << curry << endl;
		if (currx == x && curry == y) {
			cout << i+1 << " Right" << endl;
			break;
		}
		currx = 0;
		curry = 0;
		dir = 0;
		cop[i] = bentar;
	}
}