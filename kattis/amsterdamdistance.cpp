#include <bits/stdc++.h>
using namespace std;

int main() {
	float m, n;
	float r;
	cin >> m >> n >> r;
	float ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	float maxx = max(ax, bx), minx = min(ax, bx), maxy = max(ay, by), miny = min(ay, by);
	float dist = 10000000.0;
	for (int i = 0; i < maxy+1; i++) {
		float temp = ((r*(abs(i-maxy)/n)) + (r*(abs(i-miny)/n))) + (M_PI*(i/n)*r*((maxx-minx)/m));
		dist = min(dist, temp); 
	}
	cout << fixed << setprecision(15) << dist << endl;
}