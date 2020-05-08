#include <bits/stdc++.h>
using namespace std;

int main () {
    int x;
    int y;
    scanf("%d%d", &x, &y);
    if (x > 0) {
        if (y > 0) {
            printf("%d\n", 1);
        } else {
            printf("%d\n", 4);
        }
    } else {
        if (y > 0) {
            printf("%d\n", 2);

        } else {
            printf("%d\n", 3);
        }
    }
}