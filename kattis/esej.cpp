#include <bits/stdc++.h>
using namespace std;

string aux = "a";

void inc() {
	if (aux.length() == 15 && aux == "zzzzzzzzzzzzzzz") {
		aux = "a";
	}
	else {
		bool sudah = false;
		for (int i = aux.length()-1; i >= 0; i--) {
			if (aux[i] != 'z') {
				aux[i] = char(aux[i]+1);
				sudah = true;
			}
			for (int j = i+1; j < aux.length(); j++) {
				aux[j] = 'a';
			}
			if (sudah) {
				break;
			}
		}		
		if (!sudah) {
			int lng = aux.length()+1;
			aux = "";
			for (int i = 0; i < lng; i++) {
				aux += 'a';
			}
		} 
	}
}

int main() {
	int mini, maxi;
	cin >> mini >> maxi;
	int avg = (mini+maxi)/2;
	if ((mini+maxi)%2 != 0) {
		avg++;
	}
	string temp = "";
	for (int i = 0; i < avg; i++) {
		if (i == 0) {
			temp += aux;
		}
		else {
			temp += ' ';
			temp += aux;
		}
		inc();
	}
	cout << temp << endl;
}