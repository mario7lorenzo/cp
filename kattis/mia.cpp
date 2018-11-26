#include <bits/stdc++.h>
using namespace std;
int scorer(int a, int b) {
    string saver = "";
    string maxi = to_string(max(a, b)), mini = to_string(min(a, b));
    saver = maxi + mini;
    if (saver == "21") {
        return 5;
    }
    else if (maxi == mini) {
        return 3;
    }
    else {
        return 1;
    }

}

int main() {
    int a, b, x, y;
    while (cin >> a >> b >> x >> y) {
        if (a == 0) {
            break;
        }
        else {
            int onescore, twoscore;
            onescore = scorer(a, b);
            twoscore = scorer(x, y);
            if (onescore > twoscore) {
                cout << "Player 1 wins." << endl;
            }
            else if (onescore < twoscore) {
                cout << "Player 2 wins." << endl;
            }
            else {
                string save_one, save_two;
                string maxone = to_string(max(a, b)), minone = to_string(min(a, b)), maxtwo = to_string(max(x, y)), mintwo = to_string(min(x, y));
                save_one = maxone + minone;
                save_two = maxtwo + mintwo;
                if (stoi(save_one) < stoi(save_two)) {
                    cout << "Player 2 wins." << endl;
                }
                else if (stoi(save_one) > stoi(save_two)) {
                    cout << "Player 1 wins." << endl;
                }
                else {
                    cout << "Tie." << endl;
                }
            
            }

        }
    }
}