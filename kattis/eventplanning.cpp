#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, b, h, w;
	cin >> n >> b >> h >> w;
	vector<pair<int, vector<int>>> saver;
	for (int i = 0; i < h; i++) {
		int price;
		vector<int> temp;
		cin >> price;
		for (int j = 0; j < w; j++) {
			int av;
			cin >> av;
			temp.push_back(av);
		}
		saver.emplace_back(price, temp);
	}
	int harga = 1e9;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			int price = saver[j].first;
			int temp = saver[j].second[i];
			if ((n*price < harga) && (temp >= n)) {
				harga = n*price;
			}
		}
	}
	if (harga > b) {
		cout << "stay home" << endl;
	}
	else {
		cout << harga << endl;
	}
}