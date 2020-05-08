#include <bits/stdc++.h>
using namespace std;
#define pb push_back

long long inversion(vector<int> &arr) {
    int size = arr.size() / 2;
    if (size == 0) return 0;
    vector<int> kiri(arr.begin(), arr.begin() + size);
    vector<int> kanan(arr.begin() + size, arr.end());
    long long ans = inversion(kiri) + inversion(kanan);
    kiri.pb(1e9+3); kanan.pb(1e9+3);
    int p = 0, q = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (kiri[p] < kanan[q]) {
            arr[i] = kiri[p];
            p++;
        }
        else {
            arr[i] = kanan[q];
            q++;
            ans += kiri.size() - p - 1;
        }
    }
    // for (int x : arr) printf("%d ", x);
    // printf("\n");
    return ans;
}

int main() {
    long long tot;
    cin >> tot;
    vector<int> lst;
    for (long long i = 0; i < tot; i++) {
        long long x;
        cin >> x;
        lst.push_back(x);
    }
    long long final = inversion(lst);
    // for (int x : lst) printf("%d ", x);
    // printf("\n");
    cout << final << endl;
}