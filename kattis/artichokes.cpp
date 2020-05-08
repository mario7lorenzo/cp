#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
    int p, a, b, c, d, n;
    cin >> p >> a >> b >> c >> d >> n;
    vector<double> harga;
    for (int i = 1; i <= n; i++) {
        double price;
        price = p * (sin(a*i + b) + cos(c*i + d) + 2);
        harga.push_back(price);
    }
    double maxi = 0.0;
    double saver = -1e9;
    for (int i = 0; i < harga.size(); i++) {
        maxi = max(maxi, saver - harga[i]);
        saver = max(saver, harga[i]);
    }
    cout << fixed << setprecision(6) << maxi << endl;
}