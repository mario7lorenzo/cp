#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<vector<int>> v;
    v.resize(28, vector<int>(28));

    for(int i = 0; i < 28; i++) {
        for(int j = i; j < 28; j++) {
            v[i][j] = min(j-i, (28-j) + i);
            v[j][i] = v[i][j];
        }
    }
	int testcase;
	cin >> testcase;
	double segment = (M_PI*60.0)/28.0;
	bool isfirst = true;
	for (int i = 0; i < testcase; i++) {
		if (isfirst) {
			cin.ignore();
			isfirst = false;
		}
		string p;
		getline(cin, p);
		int pos = int(p[0]) - int('A');
		double dist = 0.0;
		for(int j = 1; j < p.length(); j++) {
            int spot1, spot2;
            spot1 = p[j-1] - 'A';
            spot2 = p[j] - 'A';

            if(p[j-1] == ' ') {
                spot1 = 26;
            }
            if(p[j-1] == '\'') {
                spot1 = 27;
            }
            if(p[j] == ' ') {
                spot2 = 26;
            }
            if(p[j] == '\'') {
                spot2 = 27;
            }

            dist += v[spot1][spot2];
        }
		cout << fixed << setprecision(10) << (dist*segment/15) + p.length()<< endl;
	}
}