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
	public static ArrayList<Node>[] am = new ArrayList[1];
	public static int[] dist = new int[1];
	public static int[] parents = new int[1];
	public static int[][] grid = new int[1][1];

	public static void dijkstra(int x) {
		PriorityQueue<Node> pq = new PriorityQueue<>();
		dist[x] = 0;
		pq.add(new Node(x, dist[x]));

		while(!pq.isEmpty()) {
			Node coor = pq.peek();
			pq.remove();

			int u = coor.vtx;
			int w = coor.weight;

			// System.out.println("ini curr " + u);

			if (w > dist[u]) {
				continue;
			}

			for (Node p : am[u]) {
				int v = p.vtx;
				// System.out.println("ini vertexnya " + v);
				int weight = p.weight;

				if (dist[v] > dist[u] + weight) {
					dist[v] = dist[u] + weight;
					pq.add(new Node(v, dist[v]));
					parents[v] = u;
				}
			}
		}
	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int inf = 1000000000;

		while (true) {
			int h = io.getInt();
			int w = io.getInt();

			if (h == 0 && w == 0) {
				break;
			}

			am = new ArrayList[(h * w) + 2];
			dist = new int[(h * w) + 2];
			parents = new int[(h * w) + 2];
			grid = new int[h][w];
			int[] move = new int[]{-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};

			for (int i = 0; i < (h * w) + 2; i++) {
				am[i] = new ArrayList<>();
				dist[i] = inf;
			}

			for (int i = 0; i < h; i++) {
				String ln = io.getWord();

				for (int j = 1; j <= w; j++) {
					int hashed = (w * i) + j;
					int val = Character.getNumericValue(ln.charAt(j - 1));

					for (int k = 0; k < 8; k++) {
						int neighbor = hashed + (move[2 * k] * w) + move[(2 * k) + 1];
						int coor_h = i + move[2 * k];
						int coor_w = j - 1 + move[(2 * k) + 1];

						if (coor_h >= 0 && coor_h < h && coor_w >= 0 && coor_w < w) {
							am[neighbor].add(new Node(hashed, val));
						}
					}

					if (i == 0) {
						am[0].add(new Node(hashed, val));
					}

					if (i == h - 1) {
						am[hashed].add(new Node((h * w) + 1, 0));
					}

					grid[i][j-1] = val;
				}
			}

			// for (int i = 0; i < (h * w) + 2; i++) {
			// 	io.println("Ini source sekarang " + i);

			// 	for (Node n : am[i]) {
			// 		io.println("Ini edgenya " + n.vtx + " beratnya " + n.weight);
			// 	}
			// }

			dijkstra(0);

			int curr = (h * w) + 1;
			while (curr != 0) {
				int par = parents[curr];
				if (par == 0) {
					break;
				}
				int coor_h = (par - 1) / w;
				int coor_w = (par - 1) % w;

				grid[coor_h][coor_w] = -1;
				curr = par;
			}

			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (grid[i][j] != -1) {
						io.print(grid[i][j]);
					} else {
						io.print(" ");
					}
				}
				io.println();
			}

			io.println();
		}

		io.flush(); 
	}
}