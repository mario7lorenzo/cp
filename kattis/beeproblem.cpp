#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

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
    int parent(int i) {
    	return p[i];
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
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int honey, x, y;
	cin >> honey >> x >> y;
	char grid[x+2][y+2];
	for (int i = 0; i < x+2; i++) {
		for (int j = 0; j < y+2; j++) {
			grid[i][j] = '#';
		}
	}
	UnionFind ufds((x*y)+1);
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			char t;
			cin >> t;
			grid[i][j] = t;
		}
	}
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if (grid[i][j-1] == grid[i][j] && grid[i][j] == '.') {
				ufds.unionSet((i-1)*y + (j-1), (i-1)*y+(j));
			}
			if (grid[i][j+1] == grid[i][j] && grid[i][j] == '.') {
				ufds.unionSet((i-1)*y + (j+1), (i-1)*y+(j));
			}
			if (i%2) {
				if (grid[i-1][j-1] == grid[i][j] && grid[i][j] == '.') {
					ufds.unionSet((i-2)*y + (j-1), (i-1)*y+(j));
				}
				if (grid[i-1][j] == grid[i][j] && grid[i][j] == '.') {
					ufds.unionSet((i-2)*y+(j), (i-1)*y+j);
				}
				if (grid[i+1][j-1] == grid[i][j] && grid[i][j] == '.') {
					ufds.unionSet((i)*y + (j-1), (i-1)*y+(j));
				}
				if (grid[i+1][j] == grid[i][j] && grid[i][j] == '.') {
					ufds.unionSet((i)*y+(j), (i-1)*y+j);
				}				
			}
			else {
				if (grid[i-1][j+1] == grid[i][j] && grid[i][j] == '.') {
					ufds.unionSet((i-2)*y + (j+1), (i-1)*y+(j));
				}
				if (grid[i-1][j] == grid[i][j] && grid[i][j] == '.') {
					ufds.unionSet((i-2)*y+(j), (i-1)*y+j);
				}
				if (grid[i+1][j+1] == grid[i][j] && grid[i][j] == '.') {
					ufds.unionSet((i)*y + (j+1), (i-1)*y+(j));
				}
				if (grid[i+1][j] == grid[i][j] && grid[i][j] == '.') {
					ufds.unionSet((i)*y+(j), (i-1)*y+j);
				}				
			}			
		}
	}
	priority_queue<int> pq;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			int id = (i-1)*y + j;
			if (id == ufds.parent(id) && grid[i][j] == '.') {
				pq.push(ufds.sizeOfSet(id));
			}
		}
	}
	int works = 0;
	while (honey > 0) {
		honey -= pq.top();
		pq.pop();
		works++;
	}
	cout << works << endl;
}