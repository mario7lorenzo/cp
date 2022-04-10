#include <bits/stdc++.h>
using namespace	std;


int r = -1;
int c = -1;
const int maxr = 4;
const int maxc = 4;

bool grid[maxr+2][maxc+2];
bool is_visited[maxr+2][maxc+2];

int count_ones(int curr_r, int curr_c) {
	if (curr_r < 1 || curr_r > r || curr_c < 1 ||curr_c > c || !grid[curr_r][curr_c] || is_visited[curr_r][curr_c]) {
		return 0;
	}

	is_visited[curr_r][curr_c] = true;
	return 1 +  count_ones(curr_r,curr_c-1)
	+ count_ones(curr_r-1,curr_c) + count_ones(curr_r+1,curr_c) + count_ones(curr_r,curr_c+1);
} 

int count_zeros(int curr_r, int curr_c) {
	if (curr_r < 0 || curr_r > r+1 || curr_c < 0 ||curr_c > c+1 || grid[curr_r][curr_c] || is_visited[curr_r][curr_c]) {
		return 0;
	}

	is_visited[curr_r][curr_c] = true;
	return 1 + count_zeros(curr_r-1,curr_c-1) + count_zeros(curr_r,curr_c-1) + count_zeros(curr_r+1,curr_c-1)
	+ count_zeros(curr_r-1,curr_c) + count_zeros(curr_r+1,curr_c) + count_zeros(curr_r-1,curr_c+1) + count_zeros(curr_r,curr_c+1)
	+ count_zeros(curr_r+1,curr_c+1);
}

void disp_grid() {
	for (int i = 0; i < maxr+2; i++) {
		for (int j = 0; j < maxc+2; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}
int main() {
	cin >> r >> c;

	int ans = 0;
	for (int mask = 1; mask < 1 << (r*c); mask++) {
		int r_one = -1;
		int c_one = -1;
		int r_zero = -1;
		int c_zero = -1;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				bool bit = (mask >> (i*c + j)) & 1;
				grid[i+1][j+1] = bit;

				if (bit && r_one == -1) {
					r_one = i+1;
					c_one = j+1;
				} else if (!bit && r_zero == -1) {
					r_zero = i+1;
					c_zero = j+1;
				}
			}
		}
		// disp_grid();

		int ones = __builtin_popcount(mask);
		int zeros = (r+2)*(c+2) - ones;

		// cout << r_one << ' ' << c_one << endl;

		memset(is_visited, false, sizeof is_visited);
		int connected_ones = count_ones(r_one, c_one);
		// cout << connected_ones << endl;
		if (ones != connected_ones) {
			continue;
		}

		memset(is_visited, false, sizeof is_visited);
		int connected_zeros = count_zeros(r_zero, c_zero);

		if (r_zero != -1 and zeros != connected_zeros) {
			continue;
		}

		ans += 1;
	}

	cout << ans << endl;
}