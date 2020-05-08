#include <bits/stdc++.h>
using namespace std;

map<int, string> saver;

int main() {
	int cups;
	cin >> cups;
	for(int i = 0; i < cups; i++) {
        int size;
        string color;
        cin.ignore();
        if(isalpha(cin.peek())) {
            cin >> color;
            cin >> size;
            size *= 2;
        }
        else {
            cin >> size;
            cin >> color;
        }
		saver[size] = color;
	}
	map<int, string>::iterator itr;
	for (itr = saver.begin(); itr != saver.end(); itr++) {
		cout << itr->second << endl;
	}
}