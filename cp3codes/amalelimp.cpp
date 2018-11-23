#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

// 1. Implementing AM, AL, EL

int main() {
	int v, e, neighbor, id, weight, a, b;
	int am[100][100];
	vector<vii> al;
	priority_queue<pair<int, ii>> el;
	// AM implementation
	cin >> v;
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			int temp;
			cin >> temp;
			am[i][j] = temp;
		}
	}
	// AL implementation
	cin >> v;
	for (int i = 0; i < v; i++) {
		cin >> neighbor;
		vii temp;
		for (int j = 0; j < neighbor; j++) {
			cin >> id;
			cin >> weight;
			temp.emplace_back(id-1, weight);
		}
		al.push_back(temp);
	}
	// EL implementation
	cin >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> weight;
		el.emplace(-weight, make_pair(a, b));
	}
	// Testing
	// 1. AM (0 neighbor)
	cout << "===============================" << endl;
	cout << "Neighbor of vertex 0 (AM) test:" << endl;
	cout << "===============================" << endl;
	for (int i = 0; i < v; i++) {
		if (am[0][i] != 0) {
			cout << "Edge 0-" << i << " (weight = " << am[0][i] << ")" << endl;
		}
 	}
 	// 2. AL (0 neighbor)
 	cout << "===============================" << endl;
 	cout << "Neighbor of vertex 0 (AL) test:" << endl;
 	cout << "===============================" << endl;
 	for (int i = 0; i < al[0].size(); i++) {
 		cout << "Edge 0-" << al[0][i].first << " (weight = " << al[0][i].second << ")" << endl;
  	}
  	// 3. EL (sorted in ascending weight)
  	cout << "==============================" << endl;
  	cout << " Edge List test sorted ascend " << endl;
  	cout << "==============================" << endl;
  	for (int i = 0; i < e; i++) {
  		pair<int, ii> temp = el.top();
  		el.pop();
  		cout << "No " << i+1 << ": " << "Edge " << temp.second.first << "-" << temp.second.second << " weight = " << -temp.first << endl;
  	} 
}

