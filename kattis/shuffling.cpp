#include <bits/stdc++.h>
using namespace std;

vector<int> glob, x, y;

void mergein() {
	vector<int> temp;
	for (int i = 0; i < glob.size(); i++) {
		if (i%2 == 0) {
			temp.push_back(y[i/2]);
		}
		else {
			temp.push_back(x[i/2]);
		}
	}
	glob = temp;
}

void inshuffle() {
	int div;
	div = glob.size()/2;
	x = std::vector<int>(glob.begin(), glob.begin()+div);
	y = std::vector<int>(glob.begin()+div, glob.end());
	mergein();
}

void mergeout() {
	vector<int> temp;
	for (int i = 0; i < glob.size(); i++) {
		if (i%2 == 0) {
			temp.push_back(x[i/2]);
		}
		else {
			temp.push_back(y[i/2]);
		}
	}
	glob = temp;
}

void outshuffle() {
	int div;
	if (glob.size()%2 != 0) {
		div = (glob.size()/2)+1;
	}
	else {
		div = (glob.size()/2);
	}
	x = std::vector<int>(glob.begin(), glob.begin()+div);
	y = std::vector<int>(glob.begin()+div, glob.end());
	mergeout();
}

int main() {
	int deck;
	string op;
	vector<int> ori;
	cin >> deck >> op;
	for (int i = 0; i < deck; i++) {
		ori.push_back(i);
	}
	glob = ori;
	int counter = 1;
	if (op == "in") {
		inshuffle();
		while (glob != ori) {
			inshuffle();
			counter++;
		}
	}
	else if (op == "out") {
		outshuffle();
		while (glob != ori) {
			outshuffle();
			counter++;
		}
	}
	cout << counter << endl;
}