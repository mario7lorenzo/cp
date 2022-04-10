#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> heights;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		heights.push_back(x);
	}

	int inf = 2000000000;

	vector<pair<int, int>> heights_with_index;

	for (int i = 0; i < n; i++) {
		heights_with_index.push_back(make_pair(heights[i], i));
	}

	sort(heights_with_index.begin(), heights_with_index.end());
	set<int> sorted_index;
	vector<int> buffer;
	int prev_elem = *max_element(heights.begin(), heights.end());
	vector<int> go_left;
	vector<int> go_right;

	for (int i = 0; i < n; i++) {
		go_left.push_back(-1);
		go_right.push_back(-1);
	}

	for (int i = n-1; i >= 0; i--) {
		int index = heights_with_index[i].second;
		int curr_elem = heights_with_index[i].first;
		// cout << index  << ' ' << curr_elem << endl;
		if (prev_elem != curr_elem) {
			// cout << "meqi" <<endl;
			for (auto buff : buffer) {
				sorted_index.insert(buff);
			}
			buffer.clear();
			prev_elem = curr_elem;
		}
		
		// cout << sorted_index.size() << endl;
		auto right = sorted_index.lower_bound(index);
		if (right == sorted_index.end()) {
			// cout << "crot" << endl;
			// try to check whether it has left
			if (!sorted_index.empty()) {
				right--;
				go_left[index] = *right;
			}
		} else if (right == sorted_index.begin()) {
			// only have right
			go_right[index] = *right;
		} else {
			go_right[index] = *right;
			right--;
			go_left[index] = *right;
		}

		buffer.push_back(index);
	}

	vector<int> jumps_required_to_left;
	vector<int> jumps_required_to_right;
	int maxi = *max_element(heights.begin(), heights.end());
	// cout << "jembut1" << endl;
	
	// for (auto i : go_left) {
	// 	cout << i << endl;
	// }
	
	// cout << "jembut2" << endl;
	
	// for (auto i : go_right) {
	// 	cout << i << endl;
	// }
	for (int i = 0; i < n; i++) {
		if (go_left[i] == -1) {
			if (heights[i] == maxi) {
				jumps_required_to_left.push_back(0);
			} else {
				jumps_required_to_left.push_back(inf);
			}
		} else {
			jumps_required_to_left.push_back(jumps_required_to_left[go_left[i]] + 1);
		}
	}

	for (int i = n-1; i >= 0; i--) {
		if (go_right[i] == -1) {
			if (heights[i] == maxi) {
				jumps_required_to_right.push_back(0);
			} else {
				jumps_required_to_right.push_back(inf);
			}
		} else {
			jumps_required_to_right.push_back(jumps_required_to_right[n - go_right[i] - 1] + 1);
		}
	}
	
	// cout << "lonte1" << endl;
	// for (auto i : jumps_required_to_left) {
	// 	cout << i << endl;
	// }
	
	// cout << "lonte2" << endl;
	
	// for (auto i : jumps_required_to_right) {
	// 	cout << i << endl;
	// }

	vector<int> result;

	for (int i = 0; i < n; i++) {
		result.push_back(min(jumps_required_to_right[n-i-1], jumps_required_to_left[i]));
	}

	for (auto i : result) {
		cout << i << ' ';
	}

	cout << endl;
}