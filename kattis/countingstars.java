import java.util.*;

class Pair {
	int first;
	int second;

	Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public String toString() {
		return "[" + this.first + ", " + this.second + "]";
	}
}

class Main {
	public static int r;
	public static int c;
	public static int[][] grid;
	public static int color = 1;

	public static boolean canReach(int a, int b) {
		return a >= 0 && a < r && b >= 0 && b < c;
	}

	public static void floodFill(Pair p) {
		Queue<Pair> q = new LinkedList<>();
		q.add(p);

		while(!q.isEmpty()) {
			Pair coor = q.peek();
			q.remove();

			// System.out.println(coor);
			if (grid[coor.first][coor.second] == 0) {
				if (canReach(coor.first-1, coor.second)) {
					if (grid[coor.first-1][coor.second] == 0) {
						q.add(new Pair(coor.first - 1, coor.second));
					}
				}

				if (canReach(coor.first+1, coor.second)) {
					if (grid[coor.first+1][coor.second] == 0) {
						q.add(new Pair(coor.first + 1, coor.second));
					}
				}

				if (canReach(coor.first, coor.second-1)) {
					if (grid[coor.first][coor.second-1] == 0) {
						q.add(new Pair(coor.first, coor.second - 1));
					}
				}

				if (canReach(coor.first, coor.second + 1)) {
					if (grid[coor.first][coor.second] == 0) {
						q.add(new Pair(coor.first, coor.second + 1));
					}
				}

				grid[coor.first][coor.second] = color;
			}
		}
	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int cases = 1;

		while(io.hasMoreTokens()) {
			r = io.getInt();
			c = io.getInt();
			grid = new int[r][c];

			for (int i = 0; i < r; i++) {
				String ln = io.getWord();
				for (int j = 0; j < c; j++) {
					if (ln.charAt(j) == '#') {
						grid[i][j] = -1;
					} else {
						grid[i][j] = 0;
					}
				}
			}

			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (grid[i][j] == 0) {
						floodFill(new Pair(i, j));
						color++;
					}
				}
			}

			io.println("Case " + cases + ": " + (color-1));

			color = 1;
			cases++;
		}

		io.flush();
	}
}