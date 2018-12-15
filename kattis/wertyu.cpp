#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<char, char> saver;
	saver['1'] = '\'';
	saver['2'] = '1';
	saver['3'] = '2';
	saver['4'] = '3';
	saver['5'] = '4';
	saver['6'] = '5';
	saver['7'] = '6';
	saver['8'] = '7';
	saver['9'] = '8';
	saver['0'] = '9';
	saver['-'] = '0';
	saver['='] = '-';
	saver['W'] = 'Q';
	saver['E'] = 'W';
	saver['R'] = 'E';
	saver['T'] = 'R';
	saver['Y'] = 'T';
	saver['U'] = 'Y';
	saver['I'] = 'U';
	saver['O'] = 'I';
	saver['P'] = 'O';
	saver['['] = 'P';
	saver[']'] = '[';
	saver['\\'] = ']';
	saver['S'] = 'A';
	saver['D'] = 'S';
	saver['F'] = 'D';
	saver['G'] = 'F';
	saver['H'] = 'G';
	saver['J'] = 'H';
	saver['K'] = 'J';
	saver['L'] = 'K';
	saver[';'] = 'L';
	saver['\''] = ';';
	saver['X'] = 'Z';
	saver['C'] = 'X';
	saver['V'] = 'C';
	saver['B'] = 'V';
	saver['N'] = 'B';
	saver['M'] = 'N';
	saver[','] = 'M';
	saver['.'] = ',';
	saver['/'] = '.';
	string p;
	while (getline(cin, p)) {
		for (int i = 0; i < p.length(); i++) {
			if (p[i] != ' ') {
				cout << saver[p[i]];
			}
			else {
				cout << ' ';
			}
		}
		cout << endl;
	}
}