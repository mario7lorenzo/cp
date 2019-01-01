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
	UnionFind uf(500005);
	int potion;
	cin >> potion;
	int cont = 0;
	for (int i = 0; i < potion; i++) {
		int m;
		cin >> m;
		unordered_map<int, int> repfreq;
		int pivot;
		unordered_set<int> saver;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			if (j == 0) {
				pivot = x;
				repfreq[uf.findSet(x)]++;
			}
			else {
				repfreq[uf.findSet(x)]++;
				saver.insert(x);
			}
		}
		bool can = true;
		unordered_map<int, int>::iterator itr;
		for (itr = repfreq.begin(); itr != repfreq.end(); itr++) {
			if (itr->second < uf.sizeOfSet(itr->first)) {
				can = false;
			}
		}
		if (can) {
			vector<int> temp;
			for (itr = repfreq.begin(); itr != repfreq.end(); itr++) {
				temp.push_back(itr->first);
			}
			for (int k = 1; k < temp.size(); k++) {
				uf.unionSet(temp[k-1], temp[k]);
			}
			cont++;
		}
	}
	cout << cont << endl;
}