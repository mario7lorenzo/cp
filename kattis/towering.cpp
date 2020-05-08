#include <bits/stdc++.h>
using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main() {
	int ha,hb;
	vector<int> vi;
	for (int i = 0; i < 6; i++) {
		int x;
		cin >> x;
		vi.push_back(x);
	}
	cin >> ha >> hb;
	sort(vi.begin(), vi.end());
	int hx = vi[0] + vi[1] + vi[2];
	int hy = vi[3] + vi[4] + vi[5];
	bool found = false;
	if (hx == ha && hy == hb) {
		found = true;
	} else {
		while (next_permutation(vi.begin(), vi.end())) {
			hx = vi[0] + vi[1] + vi[2];
			hy = vi[3] + vi[4] + vi[5];
			if (hx == ha && hy == hb) {
				found = true;
				break;
			}
		}
	}
	vector<int> frst{vi[0], vi[1], vi[2]};
	vector<int> scnd{vi[3], vi[4], vi[5]};
	sort(frst.begin(), frst.end(),desc);
	sort(scnd.begin(), scnd.end(),desc);
	for (auto i : frst) {
		cout << i << ' ';
	}
	for (auto i : scnd) {
		cout << i << ' ';
	}
	cout << endl;
}