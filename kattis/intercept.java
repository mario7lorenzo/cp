import java.util.*;

class Node implements Comparable<Node> {
    public int vtx;
    public Long weight;

    public Node(int vtx, long weight) {
        this.vtx = vtx;
        this.weight = weight;
    }

    @Override
    public String toString() {
    	return vtx + " " + weight;
    }

    @Override
    public int compareTo(Node another) {
    	if (this.weight - another.weight < 0) {
    		return -1;
    	} else if (this.weight - another.weight > 0) {
    		return 1;
    	}
        return 0;
    }
}

class Main {
	public static ArrayList<Node>[] al = new ArrayList[1];
	public static ArrayList<Integer>[] parents = new ArrayList[1];
	public static long[] dist = new long[1];
	public static long inf = 10000000000000000L;
	public static boolean[] is_visited = new boolean[1];
	public static double[] values = new double[1];
	public static Stack<Integer> stk = new Stack<>();
	public static double epsilon = 1E-13;
	public static int n = -1;
	public static int m = -1;

	public static void dijkstra(int x, ArrayList<Integer>[] parents, long[] dist) {
		PriorityQueue<Node> pq = new PriorityQueue<>();
		dist[x] = 0L;
		pq.add(new Node(x, dist[x]));

		while (!pq.isEmpty()) {
			Node coor = pq.peek();
			int u = coor.vtx;
			long w = coor.weight;
			pq.remove();

			if (w > dist[u]) {
				continue;
			}

			for (Node p : al[u]) {
				int v = p.vtx;
				long weight = p.weight;

				if (dist[v] > dist[u] + weight) {
					dist[v] = dist[u] + weight;
					pq.add(new Node(v, dist[v]));
					parents[v] = new ArrayList<>();
					parents[v].add(u);
				} else if (dist[v] == dist[u] + weight) {
					parents[v].add(u);
				}
			}
		}
	}

	public static void topoSort(int x) {
		is_visited[x] = true;
		for (int neighbor : parents[x]) {
			if (!is_visited[neighbor]) {
				topoSort(neighbor);
			}
		}
		stk.add(x);
	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		n = io.getInt();
		m = io.getInt();

		al = new ArrayList[n];
		parents = new ArrayList[n];
		dist = new long[n];
		values = new double[n];
		is_visited = new boolean[n];

		for (int i = 0; i < n; i++) {
			al[i] = new ArrayList<>(); 
			parents[i] = new ArrayList<>();
			dist[i] = inf;
			values[i] = 0.0;
			is_visited[i] = false;
		}

		for (int i = 0; i < m; i++) {
			int u = io.getInt();
			int v = io.getInt();
			long l = io.getLong();

			al[u].add(new Node(v, l));
		}

		int s = io.getInt();
		int t = io.getInt();

		dijkstra(s, parents, dist);

		topoSort(t);
		values[t] = 1.0;

		while (!stk.isEmpty()) {
			int node = stk.peek();
			double val = values[node] / (double)parents[node].size();
			stk.pop();

			for (int neighbor : parents[node]) {
				values[neighbor] += val;
			}
		}

		boolean is_first = true;

		for (int i = 0; i < n; i++) {
			if (1.0 - values[i] < epsilon) {
				if (is_first) {
					is_first = false;
					io.print(i);
				} else {
					io.print(" " + i);
				}
			}
		}

		io.println();
		io.flush();
	}
}