#include <bits/stdc++.h>
using namespace std;

int main() {
	double x1,y1,x2,y2,p;
    cin >> x1;
    while(x1 != 0){
        cin >> y1 >> x2 >> y2 >> p;
        double bedax = abs(x1-x2);
        double beday = abs(y1-y2);
        double x = pow(bedax, p);
        double y = pow(beday, p);
        double final = pow(x+y, 1/p);
        cout << setprecision(12) << final << endl;
        cin >> x1;
    }
}