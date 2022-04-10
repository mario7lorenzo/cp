#include<bits/stdc++.h>
using namespace std;


bool isValidIndex(int x, int y, int k) {
	return x >= 0 && x < k && y >= 0 && y < k;
}
int n = 100;
int grid[100][100];
int checked[100][100];
vector<int> vec;

bool bfs(int currheight) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			checked[i][j] = grid[i][j];
		}
	}
	bool changed = true;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			checked[i][j] -= currheight;
			
			if (checked[i][j] < 0) {
				checked[i][j] = 0;
			}
		}
	}
	checked[0][0] = -1;
	while (changed) {
		changed = 0;
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				if (checked[r][c] == -1) {
					if (isValidIndex(r-1,c,n) && checked[r-1][c] == 0) {
						checked[r-1][c] = -1;
						changed = true;
					}

					if (isValidIndex(r+1,c,n) && checked[r+1][c] == 0) {
						checked[r+1][c] = -1;
						changed = true;
					} 

					if (isValidIndex(r,c-1,n) && checked[r][c-1] == 0) {
						checked[r][c-1] = -1;
						changed= true;
					} 

					if (isValidIndex(r,c+1,n) && checked[r][c+1] == 0) {
						checked[r][c+1] = -1;
						changed = true;
					}
				}
			}
		}
	}

	return checked[n-1][n-1] == -1;
}

int binarySearch(vector<int> vec) {
	int mini = 0;
	int maxi = vec.size() - 1;

	while (mini <= maxi) {
		int mid = (mini+maxi)/2;
		// cout << mini << ' ' << maxi << endl;
		// cout << vec[mini] << ' ' << vec[maxi] << endl;
		// cout << currheight << endl;
		// cout << result << endl;
		if (bfs(vec[mid])) {
			maxi = mid-1;
		} else if (!bfs(vec[mid-1])) {
			mini = mid+1;
		} else {
			return vec[mid];
		}
		// cout << minheight << ' ' << maxheight << endl;
	}

	return ((!bfs(mini) && bfs(maxi)) ? vec[maxi] : vec[mini]);
}

int main() {
	cin >> n;
	unordered_set<int> uset;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int h;
			cin >> h;
			grid[i][j] = h;
			checked[i][j] = false;
			if (uset.find(h) == uset.end()) {
				vec.push_back(h);
				uset.insert(h);
			}
			
		}
	}
	
	
	sort(vec.begin(), vec.end());
	cout << binarySearch(vec) << endl;
}