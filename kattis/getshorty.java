import java.util.*;

class Edge implements Comparable<Edge> {
	public int to;
	public double weight;

	public Edge(int to, double weight) {
		this.to = to;
		this.weight = weight;
	}

	@Override
	public int compareTo(Edge another) {
		if (another.weight - this.weight < 0.0) {
			return -1;
		} else if (another.weight - this.weight > 0.0) {
			return 1;
		}
		return 0;
	}
}

class Main {
	public static double[] dist = new double[10050];
	public static ArrayList<Edge>[] al = new ArrayList[10050];
	public static double inf = 0.0;

	public static void dijkstra(int n) {
		dist[n] = 1.0;
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		pq.add(new Edge(n, dist[n]));

		while (!pq.isEmpty()) {
			Edge coor = pq.peek();
			pq.remove();

			int u = coor.to;
			double w = coor.weight;

			if (w < dist[u]) {
				continue;
			}

			for (Edge e : al[u]) {
				int v = e.to;
				double weight = e.weight;

				if (dist[v] < dist[u] * weight) {
					dist[v] = dist[u] * weight;
					pq.add(new Edge(v, dist[v]));
				}
			}
		}
	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);

		while (true) {
			int n = io.getInt();
			int m = io.getInt();

			if (n == 0 && m == 0) {
				break;
			}

			for (int i = 0; i < n; i++) {
				dist[i] = inf;
				al[i] = new ArrayList<>();
			}

			for (int i = 0; i < m; i++) {
				int from = io.getInt();
				int to = io.getInt();
				double weight = io.getDouble();
				al[from].add(new Edge(to, weight));
				al[to].add(new Edge(from, weight));
			}

			dijkstra(0);
			io.println(String.format("%.4f", dist[n-1]));
		}

		io.flush();
	}
}