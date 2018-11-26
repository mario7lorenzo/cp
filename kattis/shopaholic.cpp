#include <bits/stdc++.h>
using namespace std;

int main() {
    long long disc = 0;
    long long cntr;
    cin >> cntr;
    vector<int> val;
    int p;
    while (cin >> p) {
        val.push_back(p);
    }
    sort(val.begin(), val.end());
    if (val.size()%3 == 1) {
        for (int i = 1; i < val.size(); i+=3) {
            disc += val[i];
        }
    }
    else if (val.size()%3 == 2) {
        for (int i = 2; i < val.size(); i+=3) {
            disc += val[i];
        }       
    }
    else {
        for (int i = 0; i < val.size(); i+=3) {
            disc += val[i];
        }       
    }
    cout << disc << endl;
}