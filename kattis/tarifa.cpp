#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    int q; scanf("%d", &q);
    int arr[0];
    int counter = n;
    for (int i = 0; i < q; i++) {
        scanf("%d", &arr[0]);
        counter -= arr[0];
        counter += n;
    }
    printf("%d\n", counter);
}