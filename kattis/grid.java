import java.util.*;

class Pair {
	public int x;
	public int y;

	public Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int n = io.getInt();
		int m = io.getInt();
		int inf = 1000000000;
		int[][] grid = new int[n][m];
		int[][] bfsed = new int[n][m];

		for (int i = 0; i < n; i++) {
			String ln = io.getWord();
			for (int j = 0; j < m; j++) {
				grid[i][j] = Character.getNumericValue(ln.charAt(j));
				bfsed[i][j] = inf;
			}
		}

		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(0, 0));
		bfsed[0][0] = 0;

		while (!q.isEmpty()) {
			Pair coor = q.peek();
			q.remove();

			int dist = grid[coor.x][coor.y];

			if (coor.x - dist >= 0) {
				if (bfsed[coor.x - dist][coor.y] == inf) {
					bfsed[coor.x - dist][coor.y] = bfsed[coor.x][coor.y] + 1;
					q.add(new Pair(coor.x - dist, coor.y));
				}	
			}

			if (coor.x + dist < n) {
				if (bfsed[coor.x + dist][coor.y] == inf) {
					bfsed[coor.x + dist][coor.y] = bfsed[coor.x][coor.y] + 1;
					q.add(new Pair(coor.x + dist, coor.y));
				}
			}

			if (coor.y - dist >= 0) {
				if (bfsed[coor.x][coor.y - dist] == inf) {
					bfsed[coor.x][coor.y - dist] = bfsed[coor.x][coor.y] + 1;
					q.add(new Pair(coor.x , coor.y - dist));
				}	
			}

			if (coor.y + dist < m) {
				if (bfsed[coor.x][coor.y + dist] == inf) {
					bfsed[coor.x][coor.y + dist] = bfsed[coor.x][coor.y] + 1;
					q.add(new Pair(coor.x , coor.y + dist));
				}
			}
		}

		if (bfsed[n-1][m-1] == inf) {
			io.println(-1);
		} else {
			io.println(bfsed[n-1][m-1]);
		}

		io.flush();
	}
}