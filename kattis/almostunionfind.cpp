#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<long long> p, rank, setSize, sumset;
    int numSets;

public:
    UnionFind(int N) {
        setSize.assign((2*N)+2, 1);
        numSets = N;
        rank.assign((2*N)+2,0);
        p.assign((2*N)+2,0);
        sumset.assign((2*N)+2, 0);
        for (int i = 0; i <= (2*N)+1; i++) {
        	if (i > N) {
        		p[i] = i;
        	}
            else {
            	p[i] = N+i+1;
            	sumset[N+i+1] = i;
            }
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
                sumset[x] += sumset[y];
            } 
            else {
                p[x] = y;
                setSize[y] += setSize[x];
                sumset[y] += sumset[x];
                if(rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
        }
    }
    void Move(int i, int j) {
    	if (!isSameSet(i,j)) {
    		int x = findSet(i);
    		int y = findSet(j);
    		setSize[x]--;
    		setSize[y]++;
    		p[i] = y;
    		sumset[x] -= i;
    		sumset[y] += i;
    	}
    }
    int numDisjointSets() {
        return numSets;
    }
    int sizeOfSet(int i) {
        return setSize[findSet(i)];
    }
    long long sumofset(int i) {
    	return sumset[findSet(i)];
    }
};

int main() {
	int n, m;
	while (cin >> n >> m) {
		UnionFind uf(n);
		for (int i = 0; i < m; i++) {
			int comm;
			cin >> comm;
			if (comm == 1) {
				int a, b;
				cin >> a >> b;
				uf.unionSet(a, b);
			}
			else if (comm == 2) {
				int a, b;
				cin >> a >> b;
				uf.Move(a, b);
			}
			else if (comm == 3) {
				int a;
				cin >> a;
				cout << uf.sizeOfSet(uf.findSet(a)) << ' ' << uf.sumofset(uf.findSet(a)) << endl;
			}			
		}
	}
}