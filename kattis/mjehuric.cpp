#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> lst;
    int p;
    for (int i = 0; i < 5; i++) {
        cin >> p;
        lst.push_back(p);
    }
    int counter = lst.size();
    while (counter > 0) {
        for (int j = 1; j < counter; j++) {
            if (lst[j-1] > lst[j]) {
                int shadow;
                shadow = lst[j - 1];
                lst[j - 1] = lst[j];
                lst[j] = shadow;
                cout << lst[0] << " " << lst[1] << " " << lst[2] << " " << lst[3] << " " << lst[4] << endl;
            }
        }
        counter -= 1;
    }
}
