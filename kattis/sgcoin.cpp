#include <bits/stdc++.h>
using namespace std;


long long cheat(long long previousHash, string &transaction) {
	long long v = previousHash;
	for (int i = 0; i < transaction.length(); i++) {
    	v = (v * 31 + transaction[i]) % 1000000007;
  	}
  	return v;
}

long long H(long long previousHash, string &transaction,
            long long token) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}

int main() {
	long long prevhash;
	cin >> prevhash;
	string trans = "ottobebonghongsatjing";
	long long token1, hash1, token2, hash2, cheat1, cheat2;
	cheat1 = cheat(prevhash, trans);
	int i = 11;
	while (i < 100) {
		long long finv;
		if (i%10 == 0 || i == prevhash/10000000) {
			i++;
		}
		finv = i * pow(10, 7);
		// cout << "ini finv " << finv << endl;
		token1 = finv - (cheat1 * 7);
		while (token1 < 0) {
			token1 += 1e9+7;
		}
		// cout << "ini token1 " << token1 << endl;
		if (token1 >= 0 && token1 <= 1e9-1) {
			hash1 = finv;
			break;
		}
		i++;
	}
	cout << trans << ' ' << token1 << endl;
	// cout << "tes " << H(prevhash, trans, token1) << endl;
	i = 11;
	cheat2 = cheat(hash1, trans);
	while (i < 100) {
		long long finv;
		if (i%10 == 0 || i == hash1/10000000) {
			i++;
		}
		finv = i * pow(10, 7);
		// cout << "ini finv " << finv << endl;
		token2 = finv - (cheat2 * 7);
		while (token2 < 0) {
			token2 += 1e9+7;
		}
		// cout << "ini token2 " << token2 << endl;
		if (token2 >= 0 && token2 <= 1e9-1) {
			hash2 = finv;
			break;
		}
		i++;
	}
	cout << trans << ' ' << token2 << endl;
	// cout << "tes " << H(hash1, trans, token2) << endl;
}