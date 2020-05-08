#include <bits/stdc++.h>
using namespace std;

int main() {
    int total;
    cin >> total;
    for (int i = 0; i < total; i++) {
        string name, sec, birth, courses;
        cin >> name >> sec >> birth >> courses;
        if (stoi(sec.substr(0, 4)) >= 2010) {
            cout << name << " eligible" << endl;
        }
        else {
            if (stoi(birth.substr(0, 4)) >= 1991) {
                cout << name << " eligible" << endl;
            }
            else {
                if (stoi(courses) > 40) {
                    cout << name << " ineligible" << endl;
                }
                else {
                    cout << name << " coach petitions" << endl;
                }
            }
        }

    }
}