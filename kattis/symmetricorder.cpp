#include <bits/stdc++.h>
using namespace std;

int main() {
	int p;
	int sets = 1;
	while (cin >> p, p) {
		vector<string> lst;
		for (int i = 0; i < p; i++) {
			string nm;
			cin >> nm;
			lst.push_back(nm);
		}
		string arr[p];
		int sementara = 0;
		for (int i = 0; i < p; i++) {
			if (i%2) {
				arr[p-sementara-1] = lst[i];
				sementara++; 
			}
			else {
				arr[sementara] = lst[i];
			}
		}
		cout << "SET " << sets << endl;
		for (int i = 0; i < p; i++) {
			cout << arr[i] << endl;
		}
		sets ++;
	}
}