#include <bits/stdc++.h>
using namespace std;

int main() {
    string oct;
    cin >> oct;
    string bin;
    for (int i = 0; i < oct.length(); i++) {
        if (oct[i] == '0') {
            bin += "000";
        }
        if (oct[i] == '1') {
            bin += "001";
        }
        if (oct[i] == '2') {
            bin += "010";
        }
        if (oct[i] == '3') {
            bin += "011";
        }
        if (oct[i] == '4') {
            bin += "100";
        }
        if (oct[i] == '5') {
            bin += "101";
        }
        if (oct[i] == '6') {
            bin += "110";
        }
        if (oct[i] == '7') {
            bin += "111";
        }
    }
    reverse(bin.begin(), bin.end());
    while (bin.length()%4 != 0) {
        bin += '0';
    }
    reverse(bin.begin(), bin.end());
    vector<char> hex;
    for (int i = 0; i < bin.length(); i+= 4) {
        string forbit = bin.substr(i, 4);
        if(forbit == "0000") {
            hex.push_back('0');
        }
        if(forbit == "0001") {
            hex.push_back('1');
        }
        if(forbit == "0010") {
            hex.push_back('2');
        }
        if(forbit == "0011") {
            hex.push_back('3');
        }
        if(forbit == "0100") {
            hex.push_back('4');
        }
        if(forbit == "0101") {
            hex.push_back('5');
        }
        if(forbit == "0110") {
            hex.push_back('6');
        }
        if(forbit == "0111") {
            hex.push_back('7');
        }
        if(forbit == "1000") {
            hex.push_back('8');
        }
        if(forbit == "1001") {
            hex.push_back('9');
        }
        if(forbit == "1010") {
            hex.push_back('A');
        }
        if(forbit == "1011") {
            hex.push_back('B');
        }
        if(forbit == "1100") {
            hex.push_back('C');
        }
        if(forbit == "1101") {
            hex.push_back('D');
        }
        if(forbit == "1110") {
            hex.push_back('E');
        }
        if(forbit == "1111") {
            hex.push_back('F');
        }
    }
    reverse(hex.begin(), hex.end());
    while (hex.back() == '0') {
        hex.pop_back();
    }
    reverse(hex.begin(), hex.end());
    if (oct == "0") {
        cout << 0 << endl;
    }
    else {
        for (int i = 0; i < hex.size(); i++) {
            cout << hex[i];
        }
        cout << endl;
    }
}