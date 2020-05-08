#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<char, int> saver;
	string sets;
	cin >> sets;
	saver['T'] = 0;
	saver['C'] = 0;
	saver['G'] = 0;
	for (int i = 0; i < sets.length(); i++) {
		saver[sets[i]]++;
	}
	int mini = 1e9;
	unordered_map<char, int>::iterator itr;
	int total = 0;
	for (itr = saver.begin(); itr != saver.end(); itr++) {
		mini = min(mini, itr->second);
		total += pow(itr->second, 2);
	}
	total += (7*mini);
	cout << total << endl;
}