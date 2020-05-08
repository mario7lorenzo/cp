#include <bits/stdc++.h>
using namespace std;
int maxstar(int i) {
	if (i >= 1 && i <= 10) return 5;
	if (i >= 11 && i <= 15) return 4;
	if (i >= 16 && i <= 20) return 3;
	if (i >= 21 && i <= 25) return 2;
	if (i == 0) return 99999;
}

int main() {
	string record;
	cin >> record;
	int rank = 25;
	int currstars = 0;
	int streak = 0;
	for (int i = 0; i < record.length(); i++) {
		if (record[i] == 'W') {
			streak++;
			currstars++;
			if (rank >= 6 && rank <= 25) {
				if (streak >= 3) {
					currstars++;
				}
			}
			if (currstars > maxstar(rank)) {
				currstars = currstars - maxstar(rank);
				rank--;
			}
		}
		else {
			streak = 0;
			if (rank == 0) {
				continue;
			}
			else if (rank <= 20) {
				if (rank == 20 && currstars == 0) {
					continue;
				}
				else if (currstars == 0) {
					rank++;
					currstars = maxstar(rank) - 1;
				}
				else if (currstars > 0) {
					currstars--;
				}
			}
		}
	}
	if (rank == 0) {
		cout << "Legend" << endl;
	}
	else {
		cout << rank << endl;
		// cout << currstars << endl;
		// cout << streak << endl;
	}
}