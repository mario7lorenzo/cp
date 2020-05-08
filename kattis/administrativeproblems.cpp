#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin >> test;
	while (test--) {
		int cars, events;
		cin >> cars >> events;
		unordered_map<string, vector<int>> carlst;
		map<string, bool> status;
		map<string, long long> bill;
		unordered_map<string, string> mancar;
		unordered_set<string> driver, carocc;
		for (int i = 0; i < cars; i++) {
			string name;
			int cat, pick, kilo;
			cin >> name >> cat >> pick >> kilo;
			carlst[name].push_back(cat);
			carlst[name].push_back(pick);
			carlst[name].push_back(kilo);
		}
		for (int i = 0; i < events; i++) {
			int t, pr;
			string stat, name, car;
			cin >> t >> name >> stat;
			if (status.find(name) == status.end()) {
				status[name] = true;
				bill[name] = 0;
			}
			if (stat == "p") {
				cin >> car;
				if ((driver.find(name) == driver.end()) && status[name]) {
					mancar[name] = car;
					driver.insert(name);
					bill[name] += carlst[car][1];
				}
				else {
					status[name] = false;
				}
			}
			if (stat == "r") {
				cin >> pr;
				if (mancar.find(name) != mancar.end() && status[name]) {
					string mobil = mancar[name];
					driver.erase(name);
					mancar.erase(name);
					int hargakilo = carlst[mobil][2];
					hargakilo *= pr;
					bill[name] += hargakilo;
				}
				else {
					status[name] = false;
				}
			}
			if (stat == "a") {
				cin >> pr;
				if (mancar.find(name) != mancar.end() && status[name]) {
					string mobil = mancar[name];
					double harga = double(carlst[mobil][0]);
					bill[name] += (pr * carlst[mobil][0] + 99)/100;
				}
				else {
					status[name] = false;
				}
			}
		}
		unordered_map<string, string>::iterator itr;
		for (itr = mancar.begin(); itr != mancar.end(); itr++) {
			status[itr->first] = false;
		}
		map<string, long long>::iterator it;
		for (it = bill.begin(); it != bill.end(); it++) {
			if (status[it->first]) {
				cout << it->first << ' ' << it->second << endl;
			}
			else {
				cout << it->first << " INCONSISTENT" << endl;
			}
		}
	}
}