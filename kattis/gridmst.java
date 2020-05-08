import java.util.*;

class Coordinate {
	public int x;
	public int y;
	public int color;

	public Coordinate(int x, int y, int color) {
		this.x = x;
		this.y = y;
		this.color = color;
	}
}

class Pair {
	public int first;
	public int second;

	public Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}

	public int getDistance(Pair another) {
		return Math.abs(this.first - another.first) + Math.abs(this.second - another.second);
	}
}

class Edge implements Comparable<Edge> {
	public int from;
	public int to;
	public int weight;

	public Edge(int from, int to, int weight) {
		this.from = from;
		this.to = to;
		this.weight = weight;
	}

	@Override
	public int compareTo(Edge another) {
		return this.weight - another.weight != 0
		? this.weight - another.weight
		: this.from - another.from != 0
		? this.from - another.from
		: this.to - another.to;
	}

	@Override
	public String toString() {
		return "From: " + this.from + " To: " + this.to + " Weight: " + this.weight;
	}
}

class Main {
	public static boolean isInGrid(int x, int y) {
		return x >= 0 && x < 1000 && y >= 0 && y < 1000;
	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int n = io.getInt();
		int[][] grid = new int[1000][1000];

		for (int i = 0; i < 1000; i++){
			for (int j = 0; j < 1000; j++) {
				grid[i][j] = -1;
			}
		}

		Queue<Coordinate> q = new LinkedList<>();
		ArrayList<Pair> points = new ArrayList<>(); 
		// Initializing Voronoi Diagram
		int ori = 0;
		for (int i = 0; i < n; i++) {
			int x = io.getInt();
			int y = io.getInt();

			if (grid[x][y] == -1) {
				grid[x][y] = ori;
				q.add(new Coordinate(x, y, ori));
				points.add(new Pair(x, y));
				ori++;
			}
		}

		// Run BFS to get the colored Voronoi Diagram
		int[] moves = new int[]{0, 1, 0, -1, 1, 0, -1, 0};

		while (!q.isEmpty()) {
			Coordinate coor = q.peek();
			q.remove();
			int coor_x = coor.x;
			int coor_y = coor.y;
			int coor_color = coor.color;

			for (int i = 0; i < 4; i++) {
				int next_x = coor_x + moves[2 * i];
				int next_y = coor_y + moves[(2 * i) + 1];

				if (isInGrid(next_x, next_y)) {
					if (grid[next_x][next_y] == -1) {
						grid[next_x][next_y] = coor_color;
						q.add(new Coordinate(next_x, next_y, coor_color));
					}
				}
			} 
		}

		// Just get the edge if the 2 Voronoi regions are adjacent to each other.
		// Otherwise, no need since it cannot be the edge of the MST
		ArrayList<Edge> el = new ArrayList<>();

		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 1000; j++) {
				for (int k = 0; k < 4; k++) {
					int new_i = i + moves[2*k];
					int new_j = j + moves[(2*k) + 1];
					if (isInGrid(new_i, new_j)) {
						if (grid[i][j] != grid[new_i][new_j]) {
							el.add(new Edge(grid[i][j], grid[new_i][new_j], 
								points.get(grid[i][j]).getDistance(points.get(grid[new_i][new_j]))));
						}
					}
				}
			}
		}

		Collections.sort(el);

		UFDS ufds = new UFDS(ori);
		long w = 0L;

		for (Edge e : el) {
			int first = e.from;
			int second = e.to;
			if (!ufds.isSameSet(first, second)) {
				w += (long)e.weight;
				ufds.unionSet(first, second);
			}
		}

		io.println(w);
		io.flush();
	}
}