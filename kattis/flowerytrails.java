import java.util.*;

class Pair implements Comparable<Pair> {
	public int vtx;
	public int weight;
	public boolean is_counted;

	public Pair(int vtx, int weight) {
		this.vtx = vtx;
		this.weight = weight;
		is_counted = false;
	}

	@Override
	public int compareTo(Pair another) {
		return this.weight - another.weight;
	}
}

class Main {
	public static int inf = 1000000000;
	public static int[][]grid = new int[1][1];
	public static int p = -1;
	public static int[] dist = new int[1];
	public static ArrayList<Pair>[] al = new ArrayList[1];
	public static boolean[] is_visited = new boolean[1];
	public static ArrayList<Integer>[] parents = new ArrayList[1];

	public static void dijkstra(int x) {
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		dist[x] = 0;
		pq.add(new Pair(x, dist[x]));

		while (!pq.isEmpty()) {
			Pair coor = pq.peek();
			pq.remove();

			int u = coor.vtx;
			int w = coor.weight;

			// System.out.println("ini u " + u);
			if (w > dist[u]) {
				continue;
			}

			for (Pair p : al[u]) {
				int v = p.vtx;
				int weight = p.weight;
				// System.out.println("ini edge " + v + " " + weight);

				if (dist[v] > dist[u] + weight) {
					dist[v] = dist[u] + weight;
					pq.add(new Pair(v, dist[v]));
					parents[v] = new ArrayList<>();
					parents[v].add(u);
				} else if (dist[v] == dist[u] + weight) {
					parents[v].add(u);
				}
			}
		}
	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		p = io.getInt();
		int t = io.getInt();

		grid = new int[p][p];
		al = new ArrayList[p];
		dist = new int[p];
		is_visited = new boolean[p];
		parents = new ArrayList[p];

		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				if (i == j) {
					grid[i][j] = 0;
				} else {
					grid[i][j] = inf;
				}
			}
			dist[i] = inf;
			al[i] = new ArrayList<>();
			parents[i] = new ArrayList<>();
		}

		for (int i = 0; i < t; i++) {
			int p1 = io.getInt();
			int p2 = io.getInt();
			int l = io.getInt();

			al[p1].add(new Pair(p2, l));
			al[p2].add(new Pair(p1, l));
			
			if (grid[p1][p2] > l) {
				grid[p1][p2] = l;
				grid[p2][p1] = l;
			}
		}

	

		dijkstra(0);
		
		Queue<Integer> q = new LinkedList<>();
		q.add(p - 1);
		int curr_tot = 0;

		while (!q.isEmpty()) {
			int ind = q.peek();
			q.remove();

			if (!is_visited[ind]) {
				is_visited[ind] = true;

				for (int p : parents[ind]) {
					curr_tot += grid[ind][p];
					q.add(p);
				}
			}
		}

		io.println(curr_tot * 2);
		io.flush();
	}
}