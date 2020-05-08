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
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);

		int r = io.getInt();
		int c = io.getInt();
		char[][] grid = new char[r][c];

		for (int i = 0; i < r; i++) {
			String ln = io.getWord();

			for (int j = 0; j < c; j++) {
				grid[i][j] = ln.charAt(j);
			}
		}

		int[][] guy = new int[r][c];
		int[][] fire = new int[r][c];

		Queue<Pair> guy_queue = new LinkedList<>();
		Queue<Pair> fire_queue = new LinkedList<>();

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] == '#') {
					guy[i][j] = -1;
					fire[i][j] = -1;
				} else {
					guy[i][j] = 1000000000;
					fire[i][j] = 1000000000;
					if (grid[i][j] == 'J') {
						guy[i][j] = 0;
						guy_queue.add(new Pair(i, j));
					} else if (grid[i][j] == 'F') {
						fire[i][j] = 0;
						fire_queue.add(new Pair(i, j));
					}
				}
			}
		}

		while(!guy_queue.isEmpty()) {
			Pair coor = guy_queue.peek();
			guy_queue.remove();

			if (coor.first - 1 >= 0 && coor.first - 1 < r && coor.second >= 0 && coor.second < c) {
				if (guy[coor.first - 1][coor.second] > guy[coor.first][coor.second] + 1) {
					guy[coor.first - 1][coor.second] = guy[coor.first][coor.second] + 1;
					guy_queue.add(new Pair(coor.first - 1, coor.second));
				}
			}

			if (coor.first + 1 >= 0 && coor.first + 1 < r && coor.second >= 0 && coor.second < c) {
				if (guy[coor.first + 1][coor.second] > guy[coor.first][coor.second] + 1) {
					guy[coor.first + 1][coor.second] = guy[coor.first][coor.second] + 1;
					guy_queue.add(new Pair(coor.first + 1, coor.second));

				}
			}

			if (coor.first >= 0 && coor.first < r && coor.second - 1 >= 0 && coor.second - 1 < c) {
				if (guy[coor.first][coor.second - 1] > guy[coor.first][coor.second] + 1) {
					guy[coor.first][coor.second - 1] = guy[coor.first][coor.second] + 1;
					guy_queue.add(new Pair(coor.first, coor.second - 1));

				}
			}

			if (coor.first >= 0 && coor.first < r && coor.second + 1 >= 0 && coor.second + 1 < c) {
				if (guy[coor.first][coor.second + 1] > guy[coor.first][coor.second] + 1) {
					guy[coor.first][coor.second + 1] = guy[coor.first][coor.second] + 1;
					guy_queue.add(new Pair(coor.first, coor.second + 1));

				}
			}
		}

		while(!fire_queue.isEmpty()) {
			Pair coor = fire_queue.peek();
			fire_queue.remove();

			if (coor.first - 1 >= 0 && coor.first - 1 < r && coor.second >= 0 && coor.second < c) {
				if (fire[coor.first - 1][coor.second] > fire[coor.first][coor.second] + 1) {
					fire[coor.first - 1][coor.second] = fire[coor.first][coor.second] + 1;
					fire_queue.add(new Pair(coor.first - 1, coor.second));
				}
			}

			if (coor.first + 1 >= 0 && coor.first + 1 < r && coor.second >= 0 && coor.second < c) {
				if (fire[coor.first + 1][coor.second] > fire[coor.first][coor.second] + 1) {
					fire[coor.first + 1][coor.second] = fire[coor.first][coor.second] + 1;
					fire_queue.add(new Pair(coor.first + 1, coor.second));

				}
			}

			if (coor.first >= 0 && coor.first < r && coor.second - 1 >= 0 && coor.second - 1 < c) {
				if (fire[coor.first][coor.second - 1] > fire[coor.first][coor.second] + 1) {
					fire[coor.first][coor.second - 1] = fire[coor.first][coor.second] + 1;
					fire_queue.add(new Pair(coor.first, coor.second - 1));

				}
			}

			if (coor.first >= 0 && coor.first < r && coor.second + 1 >= 0 && coor.second + 1 < c) {
				if (fire[coor.first][coor.second + 1] > fire[coor.first][coor.second] + 1) {
					fire[coor.first][coor.second + 1] = fire[coor.first][coor.second] + 1;
					fire_queue.add(new Pair(coor.first, coor.second + 1));
				}
			}
		}
		
		int ans = 1000000000;
		for (int i = 0; i < r; i++) {
			if (guy[i][0] < fire[i][0]) {
				ans = Math.min(guy[i][0], ans);
			}
		}

		for (int i = 0; i < r; i++) {
			if (guy[i][c-1] < fire[i][c-1]) {
				ans = Math.min(guy[i][c-1], ans);
			}
		}

		for (int j = 0; j < c; j++) {
			if (guy[0][j] < fire[0][j]) {
				ans = Math.min(guy[0][j], ans);
			}
		}

		for (int j = 0; j < c; j++) {
			if (guy[r-1][j] < fire[r-1][j]) {
				ans = Math.min(guy[r-1][j], ans);
			}
		}

		if (ans != 1000000000) {
			io.println(ans+1);
		} else {
			io.println("IMPOSSIBLE");
		}

		io.flush();
	}
}