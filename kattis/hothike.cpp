#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> vec;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		vec.push_back(temp);
	}

	int day = 1;
	int maxi = max(vec[0], vec[2]);

	for (int i = 1; i < n-2; i++) {
		int temp = max(vec[i], vec[i+2]);
		if (temp < maxi) {
			day = i+1;
			maxi = temp;
		}
	}

	cout << day << ' ' << maxi << endl;
}