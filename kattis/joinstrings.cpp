#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int inf = 1e9;
	string arr[100010];
	int nodelst[100010];
	bool boolarr[100010];
	unordered_map<int, int> al;
	for (int i = 1; i <= n; i++) {
		string c;
		cin >> c;
		arr[i] = c;
		nodelst[i] = i;
		al[i] = inf;
		boolarr[i] = true;

	}
	for (int i = 1; i <= n-1; i++) {
		int a, b;
		cin >> a >> b;
		int temp = nodelst[a];
		nodelst[a] = nodelst[b];
		boolarr[b] = false;
		al[temp] = b;
	}
	int k;
	for (int i = 1; i <= n; i++) {
		if (boolarr[i]) {
			k = i;
			break;
		}
	}
	while (true) {
		cout << arr[k];
		if (al[k] == inf) {
			break;
		}
		else {
			k = al[k];
		}
	}
	cout << endl;
}