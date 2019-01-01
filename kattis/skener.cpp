#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	char arr[a][b];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			char z;
			cin >> z;
			arr[i][j] = z;
		}
	}
	vector<string> fin;
	for (int i = 0; i < a; i++) {
		string temp = "";
		for (int j = 0; j < b; j++) {
			char tx = arr[i][j];
			for (int k = 0; k < d; k++) {
				temp += tx;
			}
		}
		for (int k = 0; k < c; k++) {
			fin.push_back(temp);
		}
	}
	for (int i = 0; i < fin.size(); i++) {
		cout << fin[i] << endl;
	}
}