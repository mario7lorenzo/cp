#include <bits/stdc++.h>
using namespace std;

int main() {
	int frosh;
	cin >> frosh;
	map<set<int>, int> freq;
	for (int i = 0; i < frosh; i++) {
		int a,b,c,d,e;
		cin >> a >> b >> c >> d >> e;
		set<int> temp;
		temp.insert(a);
		temp.insert(b);
		temp.insert(c);
		temp.insert(d);
		temp.insert(e);
		// set<int>::iterator otto;
		// for (otto = temp.begin(); otto != temp.end(); i++) {
		// 	cout << *otto << endl;
		// }
		// cout << "=======================" << endl;
		if (freq.find(temp) == freq.end()) {
			freq[temp] = 1;
		}
		else {
			freq[temp]++;
		}
	}
	int maxi = -1;
	map<set<int>, int>::iterator itr;
	for (itr = freq.begin(); itr != freq.end(); itr++) {
		maxi = max(maxi, itr->second);
	}
	int counter = 0;
	for (itr = freq.begin(); itr != freq.end(); itr++) {
		if (itr->second == maxi) {
			counter += maxi;
		}
	}
	cout << counter << endl;
}