import java.util.*;

class Point {
	public int x;
	public int y;

	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public double getDistance(Point other) {
		return Math.sqrt((double)((this.x - other.x) * (this.x - other.x)) + (double)((this.y - other.y) * (this.y - other.y)));
	}
}

class Edge implements Comparable<Edge> {
	public int from;
	public int to;
	public double weight;

	public Edge(int from, int to, double weight) {
		this.from = from;
		this.to = to;
		this.weight = weight;
	}

	@Override
	public int compareTo(Edge another) {
		return this.weight - another.weight != 0
		? (this.weight - another.weight < 0 ? -1 : this.weight - another.weight > 0 ? 1 : 0)
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
		int tc = io.getInt();

		while (tc-- > 0) {
			int s = io.getInt();
			int p = io.getInt();

			ArrayList<Point> points = new ArrayList<>();
			ArrayList<Edge> el = new ArrayList<>();

			for (int i = 0; i < p; i++) {
				points.add(new Point(io.getInt(), io.getInt()));
			}

			for (int i = 0; i < p; i++) {
				for (int j = 0; j < p; j++) {
					if (i != j) {
						el.add(new Edge(i, j, points.get(i).getDistance(points.get(j))));
					}
				}
			}

			UFDS ufds = new UFDS(p);
			Collections.sort(el);

			ArrayList<Edge> mst_edges = new ArrayList<>();

			for (Edge e : el) {
				if (!ufds.isSameSet(e.from, e.to)) {
					mst_edges.add(e);
					ufds.unionSet(e.from, e.to);
				}
			}

			int ptr = p - 1 - s;
			io.println(String.format("%.2f", mst_edges.get(ptr).weight));
		}

		io.flush();
	}
}