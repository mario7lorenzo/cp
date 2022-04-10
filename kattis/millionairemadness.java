import java.util.*;

class Pair implements Comparable<Pair> {
	public int vtx;
	public int weight;

	public Pair(int vtx, int weight) {
		this.vtx = vtx;
		this.weight = weight;
	}

	@Override
	public int compareTo(Pair another) {
		return this.weight - another.weight;
	}
}


class Main {
	public static int[] dist = new int[1];
	public static ArrayList<Pair>[] al = new ArrayList[1];
	public static int row;
	public static int col;
	
	public static int getId(int r, int c, int rowId, int colId) {
		return r*colId + c;
	}
	public static boolean inRange(int r, int c, int rowId, int colId) {
		return r >= 0 && r < rowId && c >= 0 && c < colId;
	}

	public static void dijkstra(int x) {
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		dist[x] = 0;
		pq.add(new Pair(x, dist[x]));

		while (!pq.isEmpty()) {
			Pair p = pq.peek();
			pq.remove();

			int u = p.vtx;
			int w = p.weight;

			if (w > dist[u]) {
				continue;
			}

			for (Pair n : al[u]) {
				int v = n.vtx;
				int z = n.weight;

				if (dist[v] > Math.max(dist[u], z)) {
					dist[v] = Math.max(dist[u], z);
					pq.add(new Pair(v, dist[v]));
				}
			}
		}
	}


	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		row = io.getInt();
		col = io.getInt();

		int[][] grid = new int[row][col];
		al = new ArrayList[row*col];
		dist = new int[row*col];

		for (int i = 0; i < row*col; i++) {
			dist[i] = Integer.MAX_VALUE;
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				grid[i][j] = io.getInt();
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int id = getId(i, j, row, col);
				// System.out.println(id);
				al[id] = new ArrayList<>();

				if (inRange(i-1, j, row, col)) {
					al[id].add(new Pair(getId(i-1, j, row, col), Math.max(0, grid[i-1][j] - grid[i][j])));
				}

				if (inRange(i+1, j, row, col)) {
					al[id].add(new Pair(getId(i+1, j, row, col), Math.max(0, grid[i+1][j] - grid[i][j])));
				}

				if (inRange(i, j-1, row, col)) {
					al[id].add(new Pair(getId(i, j-1, row, col), Math.max(0, grid[i][j-1] - grid[i][j])));
				}

				if (inRange(i, j+1, row, col)) {
					al[id].add(new Pair(getId(i, j+1, row, col), Math.max(0, grid[i][j+1] - grid[i][j])));
				}
			}
		}

		dijkstra(0);
		io.println(dist[row*col-1]);
		io.flush();
	}
}