#include <bits/stdc++.h>
using namespace std;

bool cuscom1(vector<string> x, vector<string> y) {
	return stoi(x[0]) < stoi(y[0]);
}

bool cuscom2(vector<string> x, vector<string> y) {
	return stoi(x[1]) < stoi(y[1]);
}

bool cuscom3(vector<string> x, vector<string> y) {
	return x[2] < y[2];
}

int main() {
	int n;
	bool isfirst = true;
	while (cin >> n, n != 0) {
		if (isfirst) {
			isfirst = false;
		}
		else {
			cout << endl;
		}
		vector<vector<string>> lst;
		for (int i = 0; i < n; i++) {
			string time, ampm;
			cin >> time >> ampm;
			string h, m;
			string temp = "";
			for (int j = 0; j < time.length(); j++) {
				if (time[j] == ':') {
					h = temp;
					temp = "";
				}
				else {
					temp += time[j];
				}
			}
			m = temp;
			vector<string> sementara;
			if (h == "12") {
				sementara.push_back("0");
			}
			else {
				sementara.push_back(h);
			}
			sementara.push_back(m);
			sementara.push_back(ampm);
			lst.push_back(sementara);
		}
		sort(lst.begin(), lst.end(), cuscom2);
		stable_sort(lst.begin(), lst.end(), cuscom1);
		stable_sort(lst.begin(), lst.end(), cuscom3);
		for (int i = 0; i < n; i++) {
			if (lst[i][0] == "0") {
				cout << "12";
			}
			else {
				cout << lst[i][0];
			}
			cout <<':'<< lst[i][1] << ' ' << lst[i][2] << endl;
		}
	}
}