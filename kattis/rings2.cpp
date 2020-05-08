#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            if (x == 'T') {
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = 0;
            }
        }
    }
    bool berubah = true;
    int level = 1;
    while (berubah) {
        berubah = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0 && i < n-1 && j > 0 && j < m-1) {
                    if (arr[i][j] == level) {
                        if (arr[i-1][j] >= level && arr[i+1][j] >= level && arr[i][j-1] >= level && arr[i][j+1] >= level) {
                            arr[i][j]++;
                            berubah = true;
                        }
                    }                   
                }
            }
        }
        level++;
    }
    string lv = to_string(level);
    int len = lv.length();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        	if (len == 1) {
	            if (arr[i][j] == 0) {
	                cout << "..";
	            }
	            else {
	                string temp = ".";
	                temp += to_string(arr[i][j]);
	                cout << temp;
	            }        		
        	}
 			else if (len == 2) {
	            if (arr[i][j] == 0) {
	                cout << "...";
	            }
	            else if (arr[i][j] < 10) {
	                string temp = "..";
	                temp += to_string(arr[i][j]);
	                cout << temp;
	            }
	            else if (arr[i][j] >= 10) {
	            	string temp = ".";
	            	temp += to_string(arr[i][j]);
	            	cout << temp;
	            }
 			}
        }
        cout << endl;
    }
}