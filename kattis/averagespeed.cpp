#include <bits/stdc++.h>
using namespace std;

int main() {
	string p;
	double dist = 0.0;
	double currspeed = 0;
	double currdur = 0.0;
	while (getline(cin, p)) {
		string hrstr = p.substr(0, 2);
		string mnstr = p.substr(3, 2);
		string sestr = p.substr(6, 2);
		double hr = stod(hrstr);
		double mn = stod(mnstr);
		double se = stod(sestr);
		int lng = p.length();
		double dur = (3600.0*hr) + (60.0*mn) + se;
		dist += (dur-currdur)*(currspeed/3600);
		currdur = dur;
		if (lng == 8) {
			cout << fixed << setprecision(2) << p << ' ' << dist << " km" << endl;
		}
		else {
			string spstr = p.substr(9);
			double speed = stod(spstr);
			currspeed = speed;
		}
	}
}