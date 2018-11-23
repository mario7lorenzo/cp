#include <bits/stdc++.h>
using namespace std;

int main() {
    string oct;
    cin >> oct;
    long long dec = 0;
    for (int i = 0; i < oct.length(); i++) {
        string sementara = oct.substr(i, 1);
        dec += stoi(sementara) * pow(8, (oct.length() - i - 1));
    }
    char a[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    vector<char> hex;
    while (dec > 0) {
        int mod = dec%16;
        hex.push_back(a[mod]);
        dec /= 16;
    }
    if (oct == "0") {
        cout << 0 << endl;
    }
    else {
        while (hex.back() == '0') {
            hex.pop_back();
        }
        reverse(hex.begin(), hex.end());
        for (int i = 0; i < hex.size(); i++) {
            cout << hex[i];
        }
        cout << endl;
    }
}