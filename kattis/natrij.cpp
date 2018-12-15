#include <bits/stdc++.h>
using namespace std;

int main() {
	string in, fi;
	int hi, mi, si, hf, mf, sf, hd, md, sd;
	cin >> in >> fi;
	string temp = "";
	for (int i = 0; i < in.length(); i++) {
		if (in[i] == ':') {
			if (i == 2) {
				hi = stoi(temp);
			}
			else {
				mi = stoi(temp);
			}
			temp = "";
		}
		else {
			temp += in[i];
		}
	}
	si = stoi(temp);
	temp = "";
	for (int i = 0; i < fi.length(); i++) {
		if (fi[i] == ':') {
			if (i == 2) {
				hf = stoi(temp);
			}
			else {
				mf = stoi(temp);
			}
			temp = "";
		}
		else {
			temp += fi[i];
		}
	}
	sf = stoi(temp);
	if (sf < si) {
		sf += 60;
		mf--;
	}
	sd = sf-si;
	if (mf < mi) {
		mf += 60;
		hf--;
	}
	md = mf-mi;
	if (hf < hi) {
		hf += 24;
	}
	hd = hf-hi;
	string finh = "0", finm = "0", fins = "0";
	if (hd < 10) {
		finh += to_string(hd);
	}
	else {
		finh = to_string(hd);
	}
	if (md < 10) {
		finm += to_string(md);
	}
	else {
		finm = to_string(md);
	}
	if (sd < 10) {
		fins += to_string(sd);
	}
	else {
		fins = to_string(sd);
	}
	if (hd == 0 && md == 0 && sd == 0) {
		finh = "24";
		finm = "00";
		fins = "00";
	}
	cout << finh << ':' << finm << ':' << fins << endl;
}