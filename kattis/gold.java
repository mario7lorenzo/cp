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
	public static boolean[][] is_safe = new boolean[1][1];
	public static boolean[][] is_visited = new boolean[1][1];
	public static char[][] grid = new char[1][1];
	public static int w = -1;
	public static int h = -1;

	public static boolean isOk(int a, int b) {
		return grid[a][b] != 'T' && 
		(isOutofRange(a-1, b) ? true : grid[a-1][b] != 'T') &&
		(isOutofRange(a+1, b) ? true : grid[a+1][b] != 'T') &&
		(isOutofRange(a, b-1) ? true : grid[a][b-1] != 'T') &&
		(isOutofRange(a, b+1) ? true : grid[a][b+1] != 'T');
	}

	public static boolean isOutofRange(int a, int b) {
		return a < 0 || a >= h || b < 0 || b >= w;
	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		w = io.getInt();
		h = io.getInt();

		is_safe = new boolean[h][w];
		grid = new char[h][w];
		is_visited = new boolean[h][w];

		int player_w = -1;
		int player_h = -1;

		for (int i = 0; i < h; i++) {
			String ln = io.getWord();
			for (int j = 0; j < w; j++) {
				grid[i][j] = ln.charAt(j);
				if (grid[i][j] == 'P') {
					player_h = i;
					player_w = j;
				}
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				// io.println(i + " " + j);
				is_safe[i][j] = isOk(i, j);
				is_visited[i][j] = false;
				// io.println(is_safe[i][j]);
			}
		}

		Queue<Pair> q = new LinkedList<>();

		q.add(new Pair(player_h, player_w));
		int[] moves = new int[]{0, 1, 0, -1, 1, 0, -1, 0};
		int golds = 0;
		is_visited[player_h][player_w] = true;
		while (!q.isEmpty()) {
			Pair p = q.peek();
			q.remove();
			int curr_h = p.first;
			int curr_w = p.second;

			// io.println(p);

			if (grid[curr_h][curr_w] == 'G') {
				golds++;
			}

			if (is_safe[curr_h][curr_w]) {
				for (int i = 0; i < 4; i++) {
					int next_h = curr_h + moves[2 * i];
					int next_w = curr_w + moves[2*i + 1];

					if (!isOutofRange(next_h, next_w)) {
						if (!is_visited[next_h][next_w] && grid[next_h][next_w] != '#') {
							is_visited[next_h][next_w] = true;
							q.add(new Pair(next_h, next_w));
						}
					}
				}
			}
		}

		io.println(golds);
		io.flush();
	}
}