#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

bool arr[2000005];

int tmp[2000005];

int main() {
    for (int i = 0; i <= 2000001; i++){
        arr[i] = true;
        tmp[i] = 1;
    }
    arr[0] = false;
    arr[1] = false;
    for (int i = 2; i <= 2000000; i++) {
        if (arr[i]) {
            for (int j = 2*i; j <= 2000000; j+=i) {
                arr[j] = false;
            }
        }
    }
    for (int i = 2; i <= 2000000; i++) {
    	if (!arr[i]) {
    		for (int j = i; j <= 2000000; j+= i) {
    			tmp[j]++;
    		} 
    	}
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int x;
        cin >> x;
        cout << tmp[x] << endl;
    }
}