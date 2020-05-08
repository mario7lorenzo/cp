import java.util.*;

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

class Pair implements Comparable<Pair> {
	public int first;
	public int second;

	public Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public int compareTo(Pair another) {
		return this.first - another.first != 0
		? this.first - another.first
		: this.second - another.second;
	}
}

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		while (true) {
			int n = io.getInt();
			int m = io.getInt();

			ArrayList<Edge> el = new ArrayList<>();

			if (n == 0 && m == 0) {
				break;
			}

			for (int i = 0; i < m; i++) {
				int u = io.getInt();
				int v = io.getInt();
				int w = io.getInt();
				el.add(new Edge(u, v, w));
				el.add(new Edge(v, u, w));
			}

			Collections.sort(el);
			UFDS ufds = new UFDS(n);
			long weight = 0;
			ArrayList<Pair> mst_edge = new ArrayList<>();
			for (int i = 0; i < 2 * m; i++) {
				Edge e = el.get(i);
				
				if (!ufds.isSameSet(e.from, e.to)) {
					weight += (long)e.weight;
					mst_edge.add(new Pair(e.from, e.to));
					ufds.unionSet(e.from, e.to);
				}
			}

			Collections.sort(mst_edge);

			if (ufds.numOfDisjointSets() != 1) {
				io.println("Impossible");
			} else {
				io.println(weight);
				for (Pair e : mst_edge) {
					io.println(e.first + " " + e.second);
				}
			}
		}

		io.flush();
	}
}