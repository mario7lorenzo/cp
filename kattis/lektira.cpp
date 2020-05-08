#include <bits/stdc++.h>
using namespace std;

string rev(string x) {
	int counter = 0;
	while (counter < x.length()-counter-1) {
		swap(x[counter], x[x.length()-counter-1]);
		counter++;
	}
	return x;
}

int main() {
	string st;
	cin >> st;
	string winner = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	for (int i = 1; i < st.length(); i++) {
		for (int j = i+1; j < st.length(); j++) {
			// cout << i << ' ' << j << endl;
			string a, b, c, res = "";
			a = st.substr(0, i);
			b = st.substr(i, j-i);
			c = st.substr(j);
			a = rev(a);
			b = rev(b);
			c = rev(c);
			res += a;
			res += b;
			res += c;
			if (winner > res) {
				winner = res;
			}
		}
	}
	cout << winner << endl;
}