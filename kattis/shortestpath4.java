import java.util.*;

class Node implements Comparable<Node> {
	public int vtx;
	public long weight;

	public Node(int vtx, long weight) {
		this.vtx = vtx;
		this.weight = weight;
	}

	@Override
	public int compareTo(Node another) {
		return this.weight - another.weight < 0 ? -1 : this.weight - another.weight > 0 ? 1 : 0;
	}

	@Override
	public String toString() {
		return "(" + vtx + ", " + weight + ")";
	}
}

class Main {
	public static ArrayList<Node>[] ori = new ArrayList[1];
	public static ArrayList<Node>[] al = new ArrayList[1];
	public static boolean[] is_visited = new boolean[1];
	public static long[] dist = new long[1];
	public static int v = -1;
	public static int k = -1;
	public static long inf = (long)1E18;

	public static void dfs(int x, int turn) {
		if (turn > k || dist[x] == inf) {

		} else {
			int ori_val = x%v;
			for (Node neighbor : ori[ori_val]) {
				int n = neighbor.vtx + (turn * v);
				long w = neighbor.weight;
				if (n < k * v) {
					if (dist[n] > dist[x] + w) {
						dist[n] = dist[x] + w;
					}

					dfs(n, turn + 1);
				}
				
			}
		}
		
	}

	public static void shortestPathDAG(int s) {
		dist[s] = 0;
		
		dfs(s, 1);
	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int tc = io.getInt();
		long inf = (long)1E18;
		boolean is_first = true;

		while (tc-- > 0) {
			if (is_first) {
				is_first = false;
			} else {
				io.println();
			}

			v = io.getInt();
			ori = new ArrayList[v];
			al = new ArrayList[31 * v];
			is_visited = new boolean[31 * v];
			dist = new long[31 * v];

			for (int i = 0; i < v; i++) {
				ori[i] = new ArrayList<>();
			}


			for (int i = 0; i < v; i++) {
				int edge = io.getInt();
				for (int j = 0; j < edge; j++) {
					int vtx = io.getInt();
					long w = io.getInt();
					ori[i].add(new Node(vtx, w));
				}
			}

			int query = io.getInt();
			while (query-- > 0) {
				int s = io.getInt();
				int t = io.getInt();
				k = io.getInt();

				for (int i = 0; i < k * v; i++) {
					is_visited[i] = false;
					dist[i] = inf;
				}

				shortestPathDAG(s);
				int tot = k * v;
				long mini = inf;
				for (int i = t; i < tot; i += v) {
					mini = Math.min(mini, dist[i]);
				}

				if (mini == inf) {
					io.println(-1);
				} else {
					io.println(mini);
				}
			}
		}

		io.flush();
	}
}