#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<char, vector<string>> fkinascii;
	for (int i = 0; i < 11; i++) {
		vector<string> temp;
		if (i == 0) {
			temp.push_back("xxxxx");
			temp.push_back("x...x");
			temp.push_back("x...x");
			temp.push_back("x...x");
			temp.push_back("x...x");
			temp.push_back("x...x");
			temp.push_back("xxxxx");
			fkinascii['0'] = temp;
		}
		if (i == 1) {
			temp.push_back("....x");
			temp.push_back("....x");
			temp.push_back("....x");
			temp.push_back("....x");
			temp.push_back("....x");
			temp.push_back("....x");
			temp.push_back("....x");
			fkinascii['1'] = temp;
		}
		if (i == 2) {
			temp.push_back("xxxxx");
			temp.push_back("....x");
			temp.push_back("....x");
			temp.push_back("xxxxx");
			temp.push_back("x....");
			temp.push_back("x....");
			temp.push_back("xxxxx");
			fkinascii['2'] = temp;
		}
		if (i == 3) {
			temp.push_back("xxxxx");
			temp.push_back("....x");
			temp.push_back("....x");
			temp.push_back("xxxxx");
			temp.push_back("....x");
			temp.push_back("....x");
			temp.push_back("xxxxx");
			fkinascii['3'] = temp;
		}
		if (i == 4) {
			temp.push_back("x...x");
			temp.push_back("x...x");
			temp.push_back("x...x");
			temp.push_back("xxxxx");
			temp.push_back("....x");
			temp.push_back("....x");
			temp.push_back("....x");
			fkinascii['4'] = temp;
		}
		if (i == 5) {
			temp.push_back("xxxxx");
			temp.push_back("x....");
			temp.push_back("x....");
			temp.push_back("xxxxx");
			temp.push_back("....x");
			temp.push_back("....x");
			temp.push_back("xxxxx");
			fkinascii['5'] = temp;
		}
		if (i == 6) {
			temp.push_back("xxxxx");
			temp.push_back("x....");
			temp.push_back("x....");
			temp.push_back("xxxxx");
			temp.push_back("x...x");
			temp.push_back("x...x");
			temp.push_back("xxxxx");
			fkinascii['6'] = temp;			
		}
		if (i == 7) {
			temp.push_back("xxxxx");
			temp.push_back("....x");
			temp.push_back("....x");
			temp.push_back("....x");
			temp.push_back("....x");
			temp.push_back("....x");
			temp.push_back("....x");
			fkinascii['7'] = temp;			
		}
		if (i == 8) {
			temp.push_back("xxxxx");
			temp.push_back("x...x");
			temp.push_back("x...x");
			temp.push_back("xxxxx");
			temp.push_back("x...x");
			temp.push_back("x...x");
			temp.push_back("xxxxx");
			fkinascii['8'] = temp;			
		}
		if (i == 9) {
			temp.push_back("xxxxx");
			temp.push_back("x...x");
			temp.push_back("x...x");
			temp.push_back("xxxxx");
			temp.push_back("....x");
			temp.push_back("....x");
			temp.push_back("xxxxx");
			fkinascii['9'] = temp;			
		}
		if (i == 10) {
			temp.push_back(".....");
			temp.push_back("..x..");
			temp.push_back("..x..");
			temp.push_back("xxxxx");
			temp.push_back("..x..");
			temp.push_back("..x..");
			temp.push_back(".....");
			fkinascii['+'] = temp;
		}
	}
	vector<vector<string>> pjg;
	for (int i = 0; i < 7; i++) {
		string otto;
		cin >> otto;
		// cout << otto << endl;
		if (i == 0) {
			for (int j = 0; j < otto.length(); j+=6) {
				vector<string> init;
				string bebong = otto.substr(j, 5);
				init.push_back(bebong);
				pjg.push_back(init);
			}
		}
		else {
			int counter = 0;
			for (int j = 0; j < otto.length(); j+=6) {
				string bebong = otto.substr(j, 5);
				// cout << bebong << endl;
				// cout << "ini sz "<< pjg[j].size() << endl;
				pjg[counter].push_back(bebong);
				// cout << "tes" << endl;
				counter++;
			}			
		}
	}
	string op = "";
	// cout << op << endl;
	for (int i = 0; i < pjg.size(); i++) {
		unordered_map<char, vector<string>>::iterator it;
		for (it = fkinascii.begin(); it != fkinascii.end(); it++) {
			if (it->second == pjg[i]) {
				op += it->first;
			}
		}
	}
	long long a, b;
	string tempo = "";
	for (int i = 0; i < op.length(); i++) {
		if (op[i] == '+') {
			a = stoi(tempo);
			tempo = "";
		}
		else {
			tempo += op[i];
		}
	}
	b = stoi(tempo);
	long long res = a + b;
	tempo = to_string(res);
	vector<vector<string>> final;
	for (int i = 0; i < tempo.length(); i++) {
		final.push_back(fkinascii[tempo[i]]);
	}
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < final.size(); j++) {
			if (j == 0) {
				cout << final[j][i];
			}
			else {
				cout << '.' << final[j][i];
			}
		}
		cout << endl;
	}
}