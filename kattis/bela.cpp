#include <bits/stdc++.h>
using namespace std;

int main() {
    int p;
    string suit;
    int counter = 0;
    string score[8][3] = {{"A", "11", "11"}, {"K", "4", "4"}, {"Q", "3", "3"}, {"J", "20", "2"}, {"T", "10", "10"}, {"9", "14", "0"}, {"8","0","0"}, {"7", "0", "0"}};
    cin >> p >> suit;
    for (int i = 0; i < 4*p; i++) {
        string sementara;
        cin >> sementara;
        string angka;
        string sut;
        angka = sementara[0];
        sut = sementara[1];
        if (sut == suit) {
            for (int j = 0; j < 8; j++) {
                if (score[j][0] == angka) {
                    counter += stoi(score[j][1]);
                }
            }   
        }
        else {
            for (int j = 0; j < 8; j++) {
                if (score[j][0] == angka) {
                    counter += stoi(score[j][2]);
                }
            }
        }
    }
    cout << counter << endl;
}
