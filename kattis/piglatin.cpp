#include <bits/stdc++.h>
using namespace std;

int main() {
	string p;
	while(getline(cin, p)) {
		vector<string> lst;
		string temp = "";
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == ' ') {
				lst.push_back(temp);
				temp = "";
			}
			else {
				temp += p[i];
			}
		}
		lst.push_back(temp);
		for (int i = 0; i < lst.size(); i++) {
			string word = lst[i];
			if (word[0] == 'a' || word[0] == 'i' || word[0] == 'u' || word[0] == 'e' || word[0] == 'o' || word[0] == 'y') {
				word += "yay";
			}
			else {
				string beforevowel = "";
				int pointer;
				for (int j = 0; j < word.length(); j++) {
					if (word[j] == 'a' || word[j] == 'i' || word[j] == 'u' || word[j] == 'e' || word[j] == 'o' || word[j] == 'y') {
						pointer = j;
						break;
					}
					else {
						beforevowel += word[j];
					}
				}
				word = word.substr(pointer);
				word += beforevowel;
				word += "ay";
			}
			if (i == 0) {
				cout << word;
			}
			else {
				cout << ' ' << word;
			}
		}
		cout << endl;
	}
}