#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	vector<queue<long long>> buckets;
	long long vs[1000000];
	for (int i = 0; i < 1000; i++) {
		queue<long long> q;
		buckets.push_back(q);
	}

	while (tc--) {
		long long n, a, b, c, x, y;
		cin >> n >> a >> b >> c >> x >> y;
		long long curr = a;
		for (int i = 0; i < n; i++) {
			vs[i] = curr;
			curr = (curr * b + a) % c;
		}
		int counter = 0;
		
		while (counter < 3) {
			for (int i = 0; i < n; i++) {
				long long ll = vs[i];
				int divisor;
				if (counter == 0) {
					divisor = 1;
				} else if (counter == 1) {
					divisor = 1000;
				} else if (counter == 2) {
					divisor = 1000000;
				}
				int digit_int = ll / divisor;
				digit_int %= 1000;
				buckets[digit_int].push(ll);
			}

			int curr = 0;
			for (int i = 0; i < 1000; i++) {
				while (!buckets[i].empty()) {
					vs[curr] = buckets[i].front();
					buckets[i].pop();
					curr++;
				}
			}
			counter++;
		}


		long long result = 0;

		for (int i = 0; i < n; i++) {
			long long ll = vs[i];
			result = (result * x + ll) % y;
		}

		cout << result << endl;
	}
}