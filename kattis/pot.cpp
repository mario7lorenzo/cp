#include <bits/stdc++.h>
using namespace std;

int main() {
	int nmbr, p;
	string temp, power;
	int counter = 0;
	cin >> nmbr;
	for (int i = 0; i < nmbr; i++) {
		cin >> p;
		temp = to_string(p);
		power = temp.substr(temp.length()-1, temp.length());
		temp = temp.substr(0, temp.length()-1);
		counter += pow(stoi(temp), stoi(power));
	}
	cout << counter << endl;
}