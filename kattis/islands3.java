import java.util.*;

class Pair {
	public int first;
	public int second;

	public Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public String toString() {
		return this.first + " " + this.second;
	}
}

class Main {
	public static char[][] grid = new char[1][1];
	public static int[][] colored = new int[1][1];
	public static int[] moves = new int[]{0,1,0,-1,1,0,-1,0};
	public static int color = 0;
	public static int r = -1;
	public static int c = -1;

	public static void floodFill() {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] == 'L' && colored[i][j] == -1) {
					color++;
					bfs(i, j);
				}
			}
		}
	}

	public static boolean isOutofRange(int a, int b) {
		return a < 0 || a >= r || b < 0 || b >= c;
	}

	public static void bfs(int r, int c) {
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(r, c));
		colored[r][c] = color;

		while (!q.isEmpty()) {
			Pair p = q.peek();
			q.remove();
			int curr_r = p.first;
			int curr_c = p.second;

			for (int i = 0; i < 4; i++) {
				int next_r = curr_r + moves[2*i];
				int next_c = curr_c + moves[2*i + 1];

				if (!isOutofRange(next_r, next_c)) {
					if (grid[next_r][next_c] != 'W' && colored[next_r][next_c] == -1) {
						colored[next_r][next_c] = color;
						q.add(new Pair(next_r, next_c));
					}
				} 
			}
		}
	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		r = io.getInt();
		c = io.getInt();

		grid = new char[r][c];
		colored = new int[r][c];

		for (int i = 0; i < r; i++) {
			String ln = io.getWord();
			for (int j = 0; j < c; j++) {
				grid[i][j] = ln.charAt(j);
				colored[i][j] = -1;
			}
		}

		floodFill();
		io.println(color);
		io.flush();
	}
}