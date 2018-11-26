#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, d, x, n, m;
    scanf("%d%d%d", &l, &d, &x);
    int counter = 0;
    for (int i = l; i < d + 1; i++) {
        int p = i;
        int sum = 0;
        while (p > 0) {
            sum += p % 10;
            p /= 10;
        }
        if (sum == x) {
            if (counter == 0) {
                n = i;
                m = i;
            }
            else {
                m = i;
            }
            counter += 1;
        }
    }
    printf("%d\n%d\n", n, m);
}