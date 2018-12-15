#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> lst;
    lst.push_back(50);
    lst.push_back(43);
    lst.push_back(25);
    sort(lst.begin(), lst.end());
    cout << lst.front() << endl;
}