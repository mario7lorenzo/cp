#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> declst;

int bintodec(string x) {
	if (declst.find(x) != declst.end()) {
		return declst[x];
	}
	else {
		int power = x.length()-1;
		int counter = 0;
		for (int i = 0; i < x.length(); i++) {
			if (x[i] == '1') {
				counter += pow(2, power);
			}
			power--;
		}
		declst[x] = counter;
		return counter;
	}
}

string dectobin(int x) {
	string temp = "";
	while (x > 0) {
		temp += to_string(x%2);
		x/=2;
	}
	reverse(temp.begin(), temp.end());
	while (temp.length() < 16) {
		temp = '0' + temp;
	}
	return temp;
}

int main() {
	int n;
	cin >> n;
	int arr[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			arr[i][j] = x;
		}
	}
	vector<string> lst;
	for (int i = 0; i < n; i++) {
		lst.push_back("xxxxxxxxxxxxxxxx");
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			else {
				int num = arr[i][j];
				string a = lst[i], b = lst[j];
				string binum = dectobin(num);
				for (int k = 0; k < 16; k++) {
					if (binum[k] == '1') {
						a[k] = '1';
						b[k] = '1';
					}
				}
				lst[i] = a;
				lst[j] = b;
			}
		}
	}
	for (int i = 0; i < lst.size(); i++) {
		string temp = lst[i];
		for (int j = 0; j < temp.length(); j++) {
			if (temp[j] == 'x') {
				temp[j] = '0';
			}
		}
		lst[i] = temp;
	}
	for (int i = 0; i < lst.size(); i++) {
		if (i == 0) {
			cout << bintodec(lst[i]);
		}
		else {
			cout << ' ' << bintodec(lst[i]);
		}
	}
	cout << endl;
}