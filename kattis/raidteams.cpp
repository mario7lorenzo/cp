#include<bits/stdc++.h>
using namespace std;

class cmp {
public:
    bool operator()(pair<string, vector<int>> a, pair<string, vector<int>> b) {
        if (a.second[0] == b.second[0]) {
            return a.first > b.first;
        }
        return a.second[0] < b.second[0];
    }
};

class cmp2 {
public:
    bool operator()(pair<string, vector<int>> a, pair<string, vector<int>> b) {
        if (a.second[1] == b.second[1]) {
            return a.first > b.first;
        }
        return a.second[1] < b.second[1];
    }
};

class cmp3 {
public:
    bool operator()(pair<string, vector<int>> a, pair<string, vector<int>> b) {
        if (a.second[2] == b.second[2]) {
            return a.first > b.first;
        }
        return a.second[2] < b.second[2];
    }
};


int main() {
	int n;
	cin >> n;
	unordered_map<string, bool> is_available;
	
	priority_queue<pair<string, vector<int>>, vector<pair<string, vector<int>>>, cmp> skill1;
	priority_queue<pair<string, vector<int>>, vector<pair<string, vector<int>>>, cmp2> skill2;
	priority_queue<pair<string, vector<int>>, vector<pair<string, vector<int>>>, cmp3> skill3;

	for (int i = 0; i < n; i++) {
		string name;
		int one, two, three;
		cin >> name >> one >> two >> three;
		is_available[name] = true;
		vector<int> skills{one, two, three};
		skill1.push(make_pair(name, skills));
		skill2.push(make_pair(name, skills));
		skill3.push(make_pair(name, skills));
	}

	for (int i = 0; i < n / 3; i++) {
		if (i != 0) {
			cout << endl;
		}
		priority_queue<string, vector<string>, greater<string>> name;
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				while (!is_available[skill1.top().first]) {
					skill1.pop();
				}
				// cout << skill1.top().first;
				name.push(skill1.top().first);
				is_available[skill1.top().first] = false;
				skill1.pop();
			} else if (j == 1) {
				while (!is_available[skill2.top().first]) {
					skill2.pop();
				}
				// cout << ' ' << skill2.top().first;
				name.push(skill2.top().first);
				is_available[skill2.top().first] = false;
				skill2.pop();
			} else {
				while (!is_available[skill3.top().first]) {
					skill3.pop();
				}
				// cout << ' ' << skill3.top().first;
				name.push(skill3.top().first);
				is_available[skill3.top().first] = false;
				skill3.pop();
			}
		}

		bool is_first = true;

		while (!name.empty()) {
			if (!is_first) {
				cout << ' ';
			}
			cout << name.top();
			name.pop();
			is_first = false;
		}
	}
	cout << endl;
}
