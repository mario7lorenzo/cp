#include <bits/stdc++.h>
using namespace std;

int timecon(string x) {
	int tot = 0;
	string temp = "";
	for (auto i : x) {
		if (i == ':') {
			tot += 60*stoi(temp);
			temp = "";
		}
		else {
			temp += i;
		}
	}
	tot += stoi(temp);
	return tot;
}

string contime (int x) {
	int mnt = x/60, sec = x%60;
	string temp = to_string(mnt);
	string tmp = to_string(sec);
	if (sec < 10) {
		tmp = '0' + tmp;
	}
	temp = temp + ':' + tmp;
	return temp;
}

int main() {
	int t, h = 0, a = 0, ind = 0, curr = 0, ht = 0, at = 0;
	cin >> t;
	while (t--) {
		char x;
		int score;
		string time;
		cin >> x >> score >> time;
		// cout << x << ' ' << score << ' ' << time << endl;
		int durr = timecon(time);
		if (x == 'H') {
			h += score;
		}
		else {
			a += score;
		}
		if (ind == 1) {
			ht += durr-curr;
		}
		else if (ind  == 2) {
			at += durr-curr;
		}
		if (h > a) {
			ind = 1;
		}
		else if (h < a) {
			ind = 2;
		}
		else if (h == a) {
			ind = 0;
		}
		if (ind != 0) {
			curr = durr;
		}
	}
	if (ind == 1) {
		ht += 1920-curr;
	}
	else if (ind == 2) {
		at += 1920-curr;
	}
	if (h > a) {
		cout << 'H';
	}
	else {
		cout << 'A';
	}
	cout << ' ' << contime(ht) << ' ' << contime(at) << endl;
}