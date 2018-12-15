#include <bits/stdc++.h>
using namespace std;

int main() {
	string note, tone;
	int cases = 1;
	unordered_map<string, int> saver;
	saver["A"] = 1;
	saver["A#"] = 2;
	saver["Bb"] = 2;
	saver["B"] = 3;
	saver["C"] = 4;
	saver["C#"] = 5;
	saver["Db"] = 5;
	saver["D"] = 6;
	saver["D#"] = 7;
	saver["Eb"] = 7;
	saver["E"] = 8;
	saver["F"] = 9;
	saver["F#"] = 10;
	saver["Gb"] = 10;
	saver["G"] = 11;
	saver["G#"] = 12;
	saver["Ab"] = 12;
	while (cin >> note >> tone) {
		unordered_map<string, int>::iterator i;
		string sim = "";
		for (i = saver.begin(); i != saver.end(); i++) {
			if (i->second == saver[note] && i->first != note) {
				sim = i->first;
				break;
			}
		}
		if (sim != "") {
			cout << "Case " << cases << ": " << sim << ' ' << tone << endl;
		}
		else {
			cout << "Case " << cases << ": UNIQUE" << endl;
		}
		cases++;
	}
}