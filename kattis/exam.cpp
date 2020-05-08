#include <bits/stdc++.h>
using namespace std;

int main() {
    int correct;
    cin >> correct;
    string myans, friendans;
    cin >> myans >> friendans;
    int counter = 0;
    for (int i = 0; i < friendans.length(); i++) {
        if (myans[i] == friendans[i]) {
            counter++;
        }
    }
    if (counter < correct) {
        cout << counter + (friendans.length() - correct) << endl;
    }
    else {
        cout << correct + (friendans.length() - counter) << endl;
    }
}