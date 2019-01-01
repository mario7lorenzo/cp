#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'

class UnionFind {
  private:
    vi p;

  public:
    UnionFind(int N) {
      for (int i = 0; i < N; i++) {
        p.push_back(i);
      }
    }
    int findSet(int i) {
    	if (p[i] != i) {
    		int tmp = p[i];
    		while (tmp != p[tmp]) {
    			tmp = p[tmp];
    		}
    		p[i] = tmp;
    	}
      	return p[i];
    }
    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
      if(!isSameSet(i,j)) {
        int x = findSet(i);
        int y = findSet(j);
        if (x < y) {
        	p[x] = y; 
        }
        else {
        	p[y] = x;
        }
      }
    }
};

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	UnionFind uf(n);
	while (q--) {
		char query;
		int x, y;
		cin >> query >> x >> y;
		if (query == '=') {
			uf.unionSet(x, y);
		}
		else {
			bool res = uf.isSameSet(x, y);
			if (res) {
				cout << "yes" << endl;
			}
			else {
				cout << "no" << endl;
			}
		}
	}
}