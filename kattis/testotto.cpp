#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    
    int curr = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > 0) {
            if (A[i] - curr > 1) {
                break;
            } else {
                curr = A[i];
            }
        }
    }
    
    return curr + 1;
}

int main() {
	vector<int> vect{1, 3, 6, 4, 1, 2};
	cout << solution(vect) << endl;
}