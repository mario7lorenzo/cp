#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    scanf("%d", &x);
    string saver = "";
    for (int i = 1; i < x + 1; i++) {
        saver = to_string(i) + " Abracadabra";
        printf("%s\n", saver.c_str());
    }
}