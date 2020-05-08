#include <bits/stdc++.h>
using namespace std;

float dist(pair<float, float> a, pair<float, float> b) {
	return sqrt(pow(a.first-b.first, 2)+ pow(a.second-b.second, 2));
}

int main() {
	float d, n;
	while (cin >> d >> n, (d != 0.0 && n != 0)) {
		pair<float, float> arr[105];
		bool fight[105];
		for (int i = 0; i < n; i++) {
			float x, y;
			cin >> x >> y;
			fight[i] = false;
			arr[i] = make_pair(x, y);
		}
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				float distance = dist(arr[i], arr[j]);
				if (distance <= d) {
					fight[i] = true;
					fight[j] = true;
				}
			}
		}
		int sour = 0, sweet = 0;
		for (int i = 0; i < n; i++) {
			if (fight[i]) {
				sour++;
			} else {
				sweet++;
			}
		}
		cout << sour << " sour, " << sweet << " sweet" << endl;
	}
}