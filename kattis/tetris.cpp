#include <bits/stdc++.h>
using namespace std;

int main() {
	int c, p;
	cin >> c >> p;
	vector<int> kolom;
	for (int i = 0; i < c; i++) {
		int x;
		cin >> x;
		kolom.push_back(x);
	}
	int counter = 0;
	if (p == 1) {
		for (int i = 0; i < kolom.size(); i++) {
			counter++;
		}
		for (int i = 0; i <= kolom.size()-4; i++) {
			if (kolom[i] == kolom[i+1] && kolom[i+1] == kolom[i+2] && kolom[i+2] == kolom[i+3]) {
				counter++;
			}
		}
	}
	if (p == 2) {
		for (int i = 0; i <= kolom.size()-2; i++) {
			if (kolom[i] == kolom[i+1]) {
				counter++;
			}
		}
	}
	if (p == 3) {
		for (int i = 0; i <= kolom.size()-3; i++) {
			if (kolom[i] == kolom[i+1] && kolom[i+1] == kolom[i+2]-1) {
				counter++;
			}
		}
		for (int i = 0; i <= kolom.size()-2; i++) {
			if (kolom[i] == kolom[i+1]+1) {
				counter++;
			}
		}
	}
	if (p == 4) {
		for (int i =  0; i <= kolom.size()-3; i++) {
			if (kolom[i] == kolom[i+1]+1 && kolom[i+1] == kolom[i+2]) {
				counter++;
			}
		}
		for (int i = 0; i <= kolom.size()-2; i++) {
			if (kolom[i] == kolom[i+1]-1) {
				counter++;
			}
		}
	}
	if (p == 5) {
		for (int i = 0; i <= kolom.size()-3; i++) {
			if (kolom[i] == kolom[i+1] && kolom[i+1] == kolom[i+2]) {
				counter++;
			}
		}
		for (int i = 0; i <= kolom.size()-2; i++) {
			if (kolom[i] == kolom[i+1]-1) {
				counter++;
			}
		}
		for (int i = 0; i <= kolom.size()-3; i++) {
			if (kolom[i] == kolom[i+2] && kolom[i+1] == kolom[i+2]-1) {
				counter++;
			}
		}
		for (int i = 0; i <= kolom.size()-2; i++) {
			if (kolom[i] == kolom[i+1]+1) {
				counter++;
			}
		}
	}
	if (p == 6) {
		for (int i = 0; i <= kolom.size()-3; i++) {
			if (kolom[i] == kolom[i+1] && kolom[i+1] == kolom[i+2]) {
				counter++;
			}
		}
		for (int i = 0; i <= kolom.size()-2; i++) {
			if (kolom[i] == kolom[i+1]) {
				counter++;
			}
		}
		for (int i = 0; i <= kolom.size()-3; i++) {
			if (kolom[i] == kolom[i+1]-1 && kolom[i+1] == kolom[i+2]) {
				counter++;
			}
		}
		for (int i = 0; i <= kolom.size()-2; i++) {
			if (kolom[i] == kolom[i+1]+2) {
				counter++;
			}
		}
	}
	if (p == 7) {
		for (int i = 0; i <= kolom.size()-3; i++) {
			if (kolom[i] == kolom[i+1] && kolom[i+1] == kolom[i+2]) {
				counter++;
			}
		}
		for (int i = 0; i <= kolom.size()-2; i++) {
			if (kolom[i] == kolom[i+1]-2) {
				counter++;
			}
		}
		for (int i = 0; i <= kolom.size()-3; i++) {
			if (kolom[i] == kolom[i+1] && kolom[i+1] == kolom[i+2]+1) {
				counter++;
			}
		}
		for (int i = 0; i <= kolom.size()-2; i++) {
			if (kolom[i] == kolom[i+1]) {
				counter++;
			}
		}
	}
	cout << counter << endl;
}