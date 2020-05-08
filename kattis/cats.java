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

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int t = io.getInt();

		while (t-- > 0) {
			long m = io.getLong();
			int c = io.getInt();

			ArrayList<Edge> el = new ArrayList<>();

			int edges = (c * (c - 1)) / 2;
			for (int i = 0; i < edges; i++) {
				int a = io.getInt();
				int b = io.getInt();
				int w = io.getInt();
				el.add(new Edge(a, b, w));
				el.add(new Edge(b, a, w));
			}

			Collections.sort(el);
			UFDS ufds = new UFDS(c);
			long cost = 0;
			for (Edge e : el) {
				if (!ufds.isSameSet(e.from, e.to)) {
					cost += e.weight;
					ufds.unionSet(e.from, e.to);
				}
			}

			if (cost + c > m) {
				io.println("no");
			} else {
				io.println("yes");
			}
		}

		io.flush();
	}
}