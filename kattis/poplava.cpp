#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, x;
	cin >> n >> x;
	if (x > (n-1)*(n-2)/2) {
		cout << -1 << endl;
	}
	else {
		vector<int> lst;
		long long maxi = (n-1)*(n-2)/2;
		lst.push_back(n);
		for (int i = 1; i < n; i++) {
			lst.push_back(i);
		}
		int temp = n-2;
		long long selisih = maxi-x;
		long long minus = 1;
		long long adder = 0;
		long long arr[1000001];
		for (int i = 0; i <= 1000000; i++) {
			if (i == 0) {
				arr[i] = 0;
			}
			else {
				arr[i] = arr[i-1] + adder;
			}
			adder++;
		}
		int ind;
		for (int i = 0; i <= 1000000; i++) {
			if (selisih < arr[i]) {
				ind = i-1;
				selisih -=arr[i-1];
				break;
			}
		}
		ind = n-1-ind;
		int pivot = ind-1; 
		vector<int> neww;
		for (int i = 0; i < ind; i++) {
			neww.push_back(lst[i]);
		}
		for (int i = n-1; i >= ind; i--) {
			neww.push_back(lst[i]);
		}
		while (selisih > 0) {
			swap(neww[pivot], neww[pivot+1]);
			pivot++;
			selisih--;
		}
		for (int i = 0; i < neww.size(); i++) {
			if (i == 0) {
				cout << neww[i];
			}
			else {
				cout << ' ' << neww[i];
			}
		}
		cout << endl;
	}
}