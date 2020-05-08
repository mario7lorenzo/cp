#include <bits/stdc++.h>
using namespace std;

class cmp {
public:
    bool operator()(pair<pair<int, int>, string> a, pair<pair<int, int>, string> b) {
        if (a.first.second == b.first.second) {
            return a.first.first > b.first.first;
        }
        return a.first.second < b.first.second;
    }
};

int main() {
    unordered_map<string, pair<int, int>> cats;
    // unordered_map<string, bool> still_exist;
    priority_queue<pair<pair<int, int>, string>, vector<pair<pair<int, int>, string>>, cmp> pq;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int command;
        cin >> command;

        if (command == 0) {
            string name;
            int severity;
            cin >> name >> severity;

            cats[name] = make_pair(i, severity);
            pq.push(make_pair(make_pair(i, severity), name));
        } else if (command == 1) {
            string name;
            int increment;
            cin >> name >> increment;

            pair<int, int> curr = cats[name];
            cats[name] = make_pair(curr.first, curr.second + increment);
            pq.push(make_pair(make_pair(curr.first, curr.second + increment), name));
        } else if (command == 2) {
            string name;
            cin >> name;

            pair<int, int> curr = cats[name];
            cats[name] = make_pair(curr.first, -1);
        } else {
            while (!pq.empty()) {
                pair<pair<int, int>, string> elem = pq.top();
                string name = elem.second;
                pair<int, int> status = elem.first;
                if (cats[name] == status) {
                    cout << name << endl;
                    break;
                }
                pq.pop();
            }

            if (pq.empty()) {
                cout << "The clinic is empty" << endl;
            }
        }
    }

}