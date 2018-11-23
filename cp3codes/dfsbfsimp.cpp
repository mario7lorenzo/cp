#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

// color definition for marker

/*  white = unvisited
	black = visited
	gray = explored
*/

#define white -1
#define black 1
#define gray 2

vector<vii> al;
vi dfs_num; // This has to be global, this is a saver whether the vertex has been visited or not

// 1. DFS Implementation

void dfs(int x) {
	cout << x << endl;
	dfs_num[x] = black; // mark that the vertex has been visited
	for (int i = 0; i < al[x].size(); i++) { // check the neighbor of vertex x
		ii vtx = al[x][i]; // note: v is a pair of a vertex (neighbor of x) and its weight
		if (dfs_num[vtx.first] == white) {
			dfs(vtx.first); //recursively doing DFS to its neighbors
		}
	}
}

// 2. Topological Sort

vi toposort;

void dfs2(int x) { // just adding topological sort
	cout << x << endl;
	dfs_num[x] = black;
	for (int i = 0; i < al[x].size(); i++) {
		ii v = al[x][i];
		if (dfs_num[v.first] == white) {
			dfs2(v.first);
		}
	}
	toposort.push_back(x); //sorting
}

// 3. Graph Checking

vi dfs_parent; // save explored

void graphcheck(int x) {
	dfs_num[x] = gray; // gray first to mark it as explored, before mark it as visited (since not all neighbor have been visited yet)
	for (int i = 0; i < al[x].size(); i++) {
		ii vtx = al[x][i];
		if (dfs_num[vtx.first] == white) { // If the neighbor is unvisited (tree edge)
			dfs_parent[vtx.first] = x; // save the parent of the neighbor to be x
			graphcheck(vtx.first); // do recursion to the neighbor
		}
		else if (dfs_num[vtx.first] == gray) { // If the neighbor is explored (either bidirectional or back edge)
			if (vtx.first == dfs_parent[x]) { // If the neighbor is the parent of x, means that it is a bidirectional edge
				cout << "Bidirectional (" << x << ", " << vtx.first << ") " << "(" << vtx.first << ", " << x << ")" << endl; 
			}
			else { // If the neighbor is not the parent of x, means that it is a back edge (cyclic detected)
				cout << "Back Edge (" << x << ", " << vtx.first << ") (Cycle)" << endl;
			}
		}
		else if (dfs_num[vtx.first] == black) { // If the neighbor is visited (forward/cross edge)
			cout << "Forward/Cross Edge (" << x << ", " << vtx.first << ")" << endl;
		}
	}

}

int main() {
	
}