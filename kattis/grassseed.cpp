#include <bits/stdc++.h>
using namespace std;

int main() {
	float cost;
	cin >> cost;
	int lawn;
	cin >> lawn;
	float total = 0.0;
	for (int i = 0; i < lawn; i++) {
		float width, length;
		cin >> width >> length;
		total += width * length;
	}
	cout << fixed << setprecision(7) << cost*total << endl;
}