#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	while (cin >> testcase, testcase != -1) {
		int curr = 0;
		int dist = 0;
		for (int i = 0; i < testcase; i++) {
			int speed, tm;
			cin >> speed >> tm;
			dist += speed*(tm-curr);
			curr = tm;
		}
		cout << dist << " miles" << endl;
	}
}