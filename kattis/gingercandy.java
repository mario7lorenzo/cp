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
		return (this.weight - another.weight < 0 ? -1 : this.weight - another.weight > 0 ? 1 : 0);
	}
}

class Edge implements Comparable<Edge> {
	public int from;
	public int to;
	public long weight;

	public Edge(int from, int to, long weight) {
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


class UFDS {
    private ArrayList<Integer> parents;
    private ArrayList<Integer> ranks;
    private ArrayList<Integer> size_of_set;
    private int num_of_set;

    public UFDS(int n) {
        this.parents = new ArrayList<>();
        this.ranks = new ArrayList<>();
        this.size_of_set = new ArrayList<>();
        this.num_of_set = n;

        for (int i = 0; i <= 2*n + 1; i++) {
            this.ranks.add(0);
            this.size_of_set.add(1);
            if (i > n) {
                this.parents.add(i);
            } else {
                this.parents.add(n + i + 1);
            }
        }
    }

    public int findSet(int x) { 
        if (parents.get(x) == x)  {
            return x;
        } else {
            int value = findSet(this.parents.get(x)); 
            parents.set(x, value);
            return value; 
        } 
    }

    public boolean isSameSet(int x, int y) { 
        return findSet(x) == findSet(y); 
    }

    public void unionSet(int m, int n) { 
        if (!isSameSet(m, n)) { 
            this.num_of_set--; 
            int x = findSet(m);
            int y = findSet(n);

            if (this.ranks.get(x) > this.ranks.get(y)) { 
                this.parents.set(y, x); 
                this.size_of_set.set(x, this.size_of_set.get(x) + this.size_of_set.get(y)); 
            } else { 
                this.parents.set(x, y); 
                this.size_of_set.set(y, this.size_of_set.get(y) + this.size_of_set.get(x));
                
                if (this.ranks.get(x) == this.ranks.get(y)) { 
                    this.ranks.set(y, this.ranks.get(y) + 1); 
                } 
            } 
        }
    }

    public int numOfDisjointSets() { 
        return this.num_of_set; 
    }
    
    public int sizeOfSet(int x) { 
        return this.size_of_set.get(findSet(x)); 
    }
}

class Main {
	public static ArrayList<Node>[] al = new ArrayList[1];
	public static ArrayList<Edge> el = new ArrayList<>();
	public static int[] dist = new int[1];
	public static UFDS ufds = new UFDS(1);
	public static int n = -1;
	public static int m = -1;
	public static long l = -1L;
	public static int t = -1;
	public static int inf = (int)1E9;
	public static int ind = 0;

	public static int kruskalCheckCycle() {
		int result = -1;

		for (Edge e : el) {
			if (ufds.isSameSet(e.from, e.to)) {
				t = e.to;
				l = e.weight;
				result = e.from;
				break;
			} else {
				ufds.unionSet(e.from, e.to);
			}
			ind++;
		}

		return result;
	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);

		n = io.getInt();
		m = io.getInt();
		long alpha = io.getLong();

		al = new ArrayList[n];
		dist = new int[n];
		ufds = new UFDS(n);

		for (int i = 0; i < n; i++) {
			al[i] = new ArrayList<>();
			dist[i] = inf;
		}

		for (int i = 0; i < m; i++) {
			int u = io.getInt() - 1;
			int v = io.getInt() - 1;
			long w = io.getLong();
			al[u].add(new Node(v, w));
			al[v].add(new Node(u, w));
			el.add(new Edge(u, v, w));
		}

		Collections.sort(el);
		int pivot = kruskalCheckCycle();
		if (pivot == -1) {
			io.println("Poor girl");
		} else {
			Queue<Integer> q = new LinkedList<>();
			q.add(pivot);
			dist[pivot] = 0;
			while (!q.isEmpty()) {
				int elem = q.peek();
				q.remove();

				for (Node n : al[elem]) {
					if (n.weight < el.get(ind).weight) {
						if (dist[n.vtx] == inf) {
							dist[n.vtx] = dist[elem] + 1;
							q.add(n.vtx);
						}
					}
				}
			}

			long k = (long)dist[t] + 1L;
			io.println((l * l) + (alpha * k));
		}

		io.flush();
	}
}