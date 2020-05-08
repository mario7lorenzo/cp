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
	public static int[] dist = new int[1];
	public static boolean[] is_visited = new boolean[1];
	public static int[] how_many = new int[1];

	public static void dijkstra(int x) {
		dist[x] = 0;
		how_many[x] = 1;
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(x, dist[x]));

		while (!pq.isEmpty()) {
			Node coor = pq.peek();
			pq.remove();

			int u = coor.vtx;
			int w = coor.weight;

			if (w > dist[u]) {
				continue;
			}

			for (Node p : al[u]) {
				int v = p.vtx;
				int weight = p.weight;

				if (dist[v] > dist[u] + weight) {
					dist[v] = dist[u] + weight;
					pq.add(new Node(v, dist[v]));
					how_many[v] = how_many[u];

				} else if (dist[v] == dist[u] + weight) {
					how_many[v] += how_many[u];
				}
			}
		}
	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);

		int v = io.getInt();
		int e = io.getInt();
		int inf = 1000000000;

		al = new ArrayList[v];
		dist = new int[v]; 
		is_visited = new boolean[v];
		how_many = new int[v];

		for (int i = 0; i < v; i++) {
			al[i] = new ArrayList<>();
			dist[i] = inf;
			is_visited[i] = false;
			how_many[i] = 0;
		}

		for (int i = 0; i < e; i++) {
			int a = io.getInt();
			int b = io.getInt();
			int w = io.getInt();

			al[a].add(new Node(b, w));
		}

		int s = io.getInt();
		int t = io.getInt();

		dijkstra(s);

		// for (int i = 0; i < v; i++) {
		// 	io.println("weight ke " + i + " " + dist[i]);
		// }

		io.println(how_many[t]);
		io.flush();
	}
}