#include <bits/stdc++.h>
using namespace std;

int main () {
    int a;
    int i;
    int results;
    scanf("%d%d", &a, &i);
    if (a == 1) {
        results = a * i;
        printf("%d\n",results);
    }
    else {
        results = (a * (i - 1)) + 1;
        printf("%d\n", results);
    }
}