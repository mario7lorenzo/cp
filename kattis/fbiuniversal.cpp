#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<char, int> saver;
	unordered_map<char, char> dir;
	saver['0'] = 0;
	saver['1'] = 1;
	saver['2'] = 2;
	saver['3'] = 3;
	saver['4'] = 4;
	saver['5'] = 5;
	saver['6'] = 6;
	saver['7'] = 7;
	saver['8'] = 8;
	saver['9'] = 9;
	saver['A'] = 10;
	saver['C'] = 11;
	saver['D'] = 12;
	saver['E'] = 13;
	saver['F'] = 14;
	saver['H'] = 15;
	saver['J'] = 16;
	saver['K'] = 17;
	saver['L'] = 18;
	saver['M'] = 19;
	saver['N'] = 20;
	saver['P'] = 21;
	saver['R'] = 22;
	saver['T'] = 23;
	saver['V'] = 24;
	saver['W'] = 25;
	saver['X'] = 26;
	dir['B'] = '8';
	dir['G'] = 'C';
	dir['I'] = '1';
	dir['O'] = '0';
	dir['Q'] = '0';
	dir['S'] = '5';
	dir['U'] = 'V';
	dir['Y'] = 'V';
	dir['Z'] = '2'; 
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int sets;
		string code;
		cin >> sets >> code;
		char check = code[8];
		long long tot = 0;
		long long cd = 0;
		for (int i = 0; i < 8; i++) {
			int val;
			if (saver.find(code[i]) == saver.end()) {
				val = saver[dir[code[i]]];
			}
			else {
				val = saver[code[i]];
			}
			tot += (pow(27, 7-i) * val);
			if (i == 0) {
				cd += 2*val;
			}
			if (i == 1) {
				cd += 4*val;
			}
			if (i == 2) {
				cd += 5*val;
			}
			if (i == 3) {
				cd += 7*val;
			}
			if (i == 4) {
				cd += 8*val;
			}
			if (i == 5) {
				cd += 10*val;
			}
			if (i == 6) {
				cd += 11*val;
			}
			if (i == 7) {
				cd += 13*val;
			}
		}
		if (saver.find(check) == saver.end()) {
			check = dir[check];
		}
		cd%= 27;
		if (cd == saver[check]) {
			cout << sets << ' ' << tot << endl;
		}
		else {
			cout << sets << " Invalid" << endl;
		}
	}
}