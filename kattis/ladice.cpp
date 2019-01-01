#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class UnionFind {
  private:
    vi p, rank, setSize;
    int numSets;

  public:
    UnionFind(int N) {
      setSize.assign(N, 1);
      numSets = N;
      rank.assign(N,0);
      p.assign(N,0);
      for (int i = 0; i < N; i++) {
        p[i] = i;
      }
    }
    int findSet(int i) {
      return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
      if(!isSameSet(i,j)) {
        numSets--;
        int x = findSet(i);
        int y = findSet(j);
        if (rank[x] > rank[y]) {
          p[y] = x;
          setSize[x] += setSize[y];
        } else {
          p[x] = y;
          setSize[y] += setSize[x];
          if(rank[x] == rank[y]) {
            rank[y]++;
          }
        }
      }
    }
    int numDisjointSets() {
      return numSets;
    }
    int sizeOfSet(int i) {
      return setSize[findSet(i)];
    }
};

int main() {
	int n, l;
	cin >> n >> l;
	UnionFind uf(l+1);
	unordered_map<int, int> saver;
	for (int i = 0; i < n; i++) {
		int a, b, newx;
		cin >> a >> b;
		// cout << a << ' ' << b << endl;
		if (!uf.isSameSet(a, b)) {
			int x = uf.findSet(a);
			int y = uf.findSet(b);
			int tot = saver[x] + saver[y];
			uf.unionSet(x, y);
			int newx = uf.findSet(x);
			saver[newx] = tot;
		}
		if (saver[uf.findSet(a)] < uf.sizeOfSet(a)) {
			saver[uf.findSet(a)]++;
			cout << "LADICA" << endl;
		}
		else {
			cout << "SMECE" << endl;
		}
	}
}