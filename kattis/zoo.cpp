#include <bits/stdc++.h>
using namespace std;

int main() {
	int many;
	int counter = 1;
	while (cin >> many, many != 0) {
		bool isfirst = true;
		map<string, int> saver;
		for (int i = 0; i < many; i++) {
			if (isfirst) {
				cin.ignore();
				isfirst = false;
			}
			string animal;
			getline(cin, animal);
			string temp = "";
			for (int i = 0; i < animal.length(); i++) {
				if (animal[i] == ' ') {
					temp = "";
				}
				else {
					temp += animal[i];
				}
			}
			string final = "";
			for (int i = 0; i < temp.length(); i++) {
				int semen = int(temp[i]);
				if (65 <= semen && semen <= 90) {
					semen += 32;
				}
				final += char(semen);
			}
			saver[final]++;
		}
		cout << "List " << counter << ":" << endl;
		map<string, int>::iterator itr;
		for (itr = saver.begin(); itr != saver.end(); itr++) {
			cout << itr->first << " | " << itr->second << endl;
		}
		counter++;
	}
}