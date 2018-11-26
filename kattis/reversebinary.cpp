#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    int i = 0;
    string saver = "";
    while (x > 0) {
        saver += to_string(x%2);
        x /= 2;
    }
    int counter = 0;
    for (int i = 0; i < saver.length(); i++) {
        if (saver[i] == '1') {
            counter += pow(2, saver.length()-i-1);
        }
    }
    cout << counter << endl; 
}