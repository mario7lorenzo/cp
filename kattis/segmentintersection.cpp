#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		float x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		float a = (y1-y2) / (x1-x2);
		float b = y2-(a*x2);
		float c = (y3-y4) / (x3-x4);
		float d = y4-(c*x4);
	}
}