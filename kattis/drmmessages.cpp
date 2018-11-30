#include <bits/stdc++.h>
using namespace std;

int main() {
	string p;
	cin >> p;
	string awal = p.substr(0, p.length()/2);
	string akhir = p.substr(p.length()/2);
	int rotbeg = 0, rotend = 0;
	for (int i = 0; i < p.length()/2; i++) {
		rotbeg += (awal[i]-'A');
		rotend += (akhir[i]-'A');
	}
	rotbeg %= 26;
	rotend %= 26;
	string awal1 = "";
	string akhir1 = "";
	for (int i = 0; i < p.length()/2; i++) {
		int temp1 = (awal[i]+rotbeg);
		int temp2 = akhir[i]+rotend;
		if (temp1 > 90) {
			awal1 += char(temp1-26);
		}
		else {
			awal1 += char(temp1);
		}
		if (temp2 > 90) {
			akhir1 += char(temp2-26);
		}
		else {
			akhir1 += char(temp2);
		}
	}
	string final = "";
	for (int i = 0; i < p.length()/2; i++) {
		int temp = awal1[i] + (akhir1[i]-'A');
		if (temp > 90) {
			final += char(temp-26);
		}
		else {
			final += char(temp);
		}
	}
	cout << final << endl;
}
