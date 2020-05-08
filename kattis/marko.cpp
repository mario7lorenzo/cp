#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<char, char> saver;
	saver['a'] = '2';
	saver['b'] = '2';
	saver['c'] = '2';
	saver['d'] = '3';
	saver['e'] = '3';
	saver['f'] = '3';
	saver['g'] = '4';
	saver['h'] = '4';
	saver['i'] = '4';
	saver['j'] = '5';
	saver['k'] = '5';
	saver['l'] = '5';
	saver['m'] = '6';
	saver['n'] = '6';
	saver['o'] = '6';
	saver['p'] = '7';
	saver['q'] = '7';
	saver['r'] = '7';
	saver['s'] = '7';
	saver['t'] = '8';
	saver['u'] = '8';
	saver['v'] = '8';
	saver['w'] = '9';
	saver['x'] = '9';
	saver['y'] = '9';
	saver['z'] = '9';
	int testcase;
	cin >> testcase;
	int correct = 0;
	vector<string> lst;
	for (int i = 0; i < testcase; i++) {
		string letter;
		cin >> letter;
		lst.push_back(letter);
	}
	string desire;
	cin >> desire;
	for (int i = 0; i < lst.size(); i++) {
		string temp = "";
		for (int j = 0; j < lst[i].length(); j++) {
			temp += saver[lst[i][j]];
		}
		if (temp == desire) {
			correct++;
		}
	}
	cout << correct << endl;
}