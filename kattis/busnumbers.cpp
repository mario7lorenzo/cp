#include <bits/stdc++.h>
using namespace std;

int main() {
    int buses;
    cin >> buses;
    vector<int> lst;
    while (buses--) {
        int x;
        cin >> x;
        lst.push_back(x);
    }
    sort(lst.begin(), lst.end());
    vector<pair<int, int>> saver;
    int many = 1, ind = 0;
    for (int i = 0; i < lst.size(); i++) {
        if (i < lst.size()-1) {
            if (lst[i]+1 == lst[i+1]) {
                many++;
            }
            else {
                if (many > 2) {
                    saver.emplace_back(ind, many);
                    ind = i+1;
                    many = 1;
                }
                else if (many == 2) {
                    saver.emplace_back(ind, 1);
                    saver.emplace_back(ind+1, 1);
                    ind = i+1;
                    many = 1;
                }
                else {
                    saver.emplace_back(ind, 1);
                    ind = i+1;
                    many = 1;
                }
            }
        }
        else {
            if (lst[i] != lst[i-1]+1) {
                saver.emplace_back(i, 1);
            }
            else if (lst[i] == lst[i-1]+1 && many == 2) {
            	saver.emplace_back(i-1, 1);
            	saver.emplace_back(i, 1);
            }
            else if (lst[i] == lst[i-1]+1 && many > 2) {
            	saver.emplace_back(ind, many);
            }
        }
    }
    for (int i = 0; i < saver.size(); i++) {
        if (i == 0) {
            if (saver[i].second > 1) {
                // cout << "ini banyak " << saver[i].second << endl;
                cout << lst[saver[i].first] << '-' << lst[saver[i].second-saver[i].first-1];
            }
            else {
                cout << lst[saver[i].first];
            }
        }
        else {
            if (saver[i].second > 1) {
                // cout << "ini banyak " << saver[i].second << endl;
                // cout << saver[i].second-saver[i].first-1 << endl;
                cout << ' ' << lst[saver[i].first] << '-' << lst[saver[i].second+saver[i].first-1];
            }
            else {
                cout << ' ' << lst[saver[i].first];
            }           
        }
    }
    cout << endl;
}
