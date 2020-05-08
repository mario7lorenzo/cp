import java.util.*;

class Node implements Comparable<Node> {
    public int vtx;
    public long weight;

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
	public static int n = -1;
	public static int m = -1;
	public static long inf = (long)1E18;
	public static ArrayList<Node>[] al = new ArrayList[1];
	public static long[] ways = new long[1];
	public static long[] dist = new long[1];

	public static void dijkstra(int s) {
		dist[s] = 0L;
		ways[s] = 1L;
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(s, dist[s]));

		while (!pq.isEmpty()) {
			Node n = pq.peek();
			pq.remove();

			int u = n.vtx;
			long w = n.weight;

			if (w > dist[u]) {
				continue;
			}

			for (Node neigh : al[u]) {
				int v = neigh.vtx;
				long weight = neigh.weight;

				if (dist[v] > dist[u] + weight) {
					dist[v] = dist[u] + weight;
					pq.add(new Node(v, dist[v]));
				}
			}
		}
	}

	public static long memoize(int x) {
		if (ways[x] != -1) {
			return ways[x];
		} else {
			long result = 0L;
			for (Node n : al[x]) {
				if (dist[n.vtx] < dist[x]) {
					result += memoize(n.vtx);
				}
			}
			ways[x] = result;
			return result;
		}
	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int home = 1;
		int office = 0;

		while (true) {
			n = io.getInt();
			if (n == 0) {
				break;
			}

			m = io.getInt();
			al = new ArrayList[n];
			ways = new long[n];
			dist = new long[n];

			for (int i = 0; i < n; i++) {
				al[i] = new ArrayList<>();
				ways[i] = -1;
				dist[i] = inf;
			}

			for (int i = 0; i < m; i++) {
				int u = io.getInt() - 1;
				int v = io.getInt() - 1;
				long w = io.getLong();

				al[u].add(new Node(v, w));
				al[v].add(new Node(u, w));
			}

			dijkstra(home);
			ways[home] = 1L;

			io.println(memoize(office));
		}
		io.flush();
	}
}