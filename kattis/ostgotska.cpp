#include <bits/stdc++.h>
using namespace std;

int main() {
	int cont = 0, tot = 0;
	string words;
	while (cin >> words) {
		for (int i = 0; i < words.length(); i++) {
			if (words[i] == 'a') {
				if (words[i+1] == 'e') {
					cont++;
					break;
				}
			}
		}
		tot++;
	}
	if ((double(cont)/double(tot))*100 >= 40) {
		cout << "dae ae ju traeligt va" << endl;
	}
	else {
		cout << "haer talar vi rikssvenska" << endl;
	}
}