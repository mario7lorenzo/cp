#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[100];
    scanf("%s", s);
    int length = strlen(s);
    int x = 1, y = 2, z = 3;
    for (int i = 0; i < length; i++) {
        if (s[i] == 'A') {
            swap(x, y);
        } 
        else if (s[i] == 'B')  {
            swap(y, z);
        }
        else {
            swap(x, z);
        }
    }
    if (x == 1) {
        printf("%d\n", 1);
    }
    else if (y == 1) {
        printf("%d\n", 2);
    }
    else {
        printf("%d\n", 3);
    }
}