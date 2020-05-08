import java.util.*;

class Node implements Comparable<Node> {
	public int vtx;
	public int weight;

	public Node(int vtx, int weight) {
		this.vtx = vtx;
		this.weight = weight;
	}

	@Override
	public int compareTo(Node another) {
		return this.weight - another.weight;
	}
}

class Main {
	public static ArrayList<Node>[] al = new ArrayList[1];
	public static int[][] compressed_graph = new int[9][9];
	public static int[] idols = new int[9];
	public static int[] dist = new int[1];
	public static int inf = 1000000000;
	public static boolean[] is_visited = new boolean[9];
	public static int idol = -1;
	public static Kattio io = new Kattio(System.in);

	public static void dijkstra(int x) {
		dist[x] = 0;
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(x, dist[x]));

		while (!pq.isEmpty()) {
			Node nd = pq.peek();
			pq.remove();
			int u = nd.vtx;
			int w = nd.weight;

			if (w > dist[u]) {
				continue;
			}

			for (Node neigh : al[u]) {
				int v = neigh.vtx;
				int weight = neigh.weight;

				if (dist[v] > dist[u] + weight) {
					dist[v] = dist[u] + weight;
					pq.add(new Node(v, dist[v]));
				}
			}
		}
	}

	public static int backtrack(int curr, int lim, int num_idol) {
		// io.println("ini curr " + curr + " " + lim + " " + num_idol);
		if (curr == 0 && is_visited[curr] && lim >= 0) {
			return num_idol;
		} else if (lim < 0) {
			return 0;
		} else {
			is_visited[curr] = true;
			int counter = 0;
			for (int i = 0; i <= idol; i++) {
				if (i == 0 && curr != 0) {
					counter = Math.max(counter, backtrack(i, lim - compressed_graph[curr][i], num_idol));
				} else if (!is_visited[i] && i != curr) {
					counter = Math.max(counter, backtrack(i, lim - compressed_graph[curr][i], num_idol + 1));
				}
			}

			is_visited[curr] = false;
			// io.println("ini resultnya " + curr + " " + lim + " " + counter);
			return counter;
		}
	}

	public static void main(String[] args) {
		int tc = io.getInt();

		while (tc-- > 0) {
			int n = io.getInt();
			int m = io.getInt();

			al = new ArrayList[n];
			dist = new int[n];

			for (int i = 0; i < 9; i++) {
				is_visited[i] = false;
			}

			for (int i = 0; i < n; i++) {
				al[i] = new ArrayList<>();

			}

			for (int i = 0; i < m; i++) {
				int a = io.getInt();
				int b = io.getInt();
				int l = io.getInt();

				al[a].add(new Node(b, l));
				al[b].add(new Node(a, l));
			}

			idol = io.getInt();
			for (int i = 0; i < idol; i++) {
				idols[i + 1] = io.getInt();
			}

			for (int j = 0; j < n; j++) {
				dist[j] = inf;
			}
			dijkstra(0);
			// io.println("ini 0");
			// for (int i = 0; i < n; i++) {
			// 	io.println(dist[i]);
			// }
			for (int i = 0; i <= idol; i++) {
				compressed_graph[0][i] = dist[idols[i]];
				compressed_graph[i][0] = dist[idols[i]];
			}


			for (int i = 1; i <= idol; i++) {
				for (int j = 0; j < n; j++) {
					dist[j] = inf;
				}
				dijkstra(idols[i]);
				// io.println("ini " + i);
				// for (int j = 0; j < n; j++) {
				// 	io.println(dist[j]);
				// }

				for (int j = 0; j <= idol; j++) {
					compressed_graph[i][j] = dist[idols[j]];
					compressed_graph[j][i] = dist[idols[j]];
				}
			}

			// for (int i = 0; i <= idol; i++) {
			// 	for (int j = 0; j <= idol; j++) {
			// 		io.println("Ini dist " + i + " ke " + j + " " + compressed_graph[i][j]); 
			// 	}
			// }

			int air_capacity = io.getInt();
			io.println(backtrack(0, air_capacity, 0));
		}

		io.flush();
	}
}