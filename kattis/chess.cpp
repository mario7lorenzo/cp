#include <bits/stdc++.h>
using namespace std;
int chartoint(char x) {
	if (x == 'A') return 1; 
	else if (x == 'B') return 2;
	else if (x == 'C') return 3;
	else if (x == 'D') return 4;
	else if (x == 'E') return 5;
	else if (x == 'F') return 6;
	else if (x == 'G') return 7;
	else if (x == 'H') return 8;
}
char inttochar(int x) {
	if (x == 1) return 'A'; 
	else if (x == 2) return 'B';
	else if (x == 3) return 'C';
	else if (x == 4) return 'D';
	else if (x == 5) return 'E';
	else if (x == 6) return 'F';
	else if (x == 7) return 'G';
	else if (x == 8) return 'H';
}

bool verifier(int x, int y) {
	if (x%2 != y%2) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int testcase;
	cin >> testcase;
	char x1, x2;
	int y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x1
}