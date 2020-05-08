#include <bits/stdc++.h>
using namespace std;

int main() {
	string p;
	int counter = 0;
	map<string, int> saver;
	while (getline(cin, p)) {
		saver[p]++;
		counter++;
	}
	map<string, int>::iterator it;
	for (it = saver.begin(); it != saver.end(); it++) {
		cout << fixed << setprecision(7) << it->first << ' ' << 100.0*double(it->second)/double(counter) << endl;
	}
}