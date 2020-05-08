import java.util.*;

class Main {
	public static ArrayList<Integer>[] al = new ArrayList[1];
	public static boolean[] is_visited = new boolean[1];
	public static PriorityQueue<Integer> diameters = new PriorityQueue<>(Collections.reverseOrder());
	public static int[] dist = new int[1];
	public static int inf = 1000000000;
	public static int c = -1;
	public static int l = -1;

	public static void findDiameter(int x) {
		int take_note = -1;
		Queue<Integer> q = new LinkedList<>();
		q.add(x);

		while (!q.isEmpty()) {
			int node = q.peek();
			q.remove();

			is_visited[node] = true;

			for (int neigh : al[node]) {
				if (!is_visited[neigh]) {
					q.add(neigh);
				}
			}

			if (q.isEmpty()) {
				take_note = node;
			}
		}

		q.add(take_note);
		int furthest = -1;

		for (int i = 0; i < c; i++) {
			is_visited[i] = false;
		}

		dist[take_note] = 0;
		while (!q.isEmpty()) {
			int node = q.peek();
			q.remove();

			is_visited[node] = true;

			for (int neigh : al[node]) {
				if (!is_visited[neigh]) {
					dist[neigh] = dist[node] + 1;
					q.add(neigh);
				}
			}

			if (q.isEmpty()) {
				furthest = node;
			}
		}

		diameters.add(dist[furthest]);
	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		c = io.getInt();
		l = io.getInt();
		al = new ArrayList[c];
		is_visited = new boolean[c];
		dist = new int[c];

		for (int i = 0; i < c; i++) {
			al[i] = new ArrayList<>();
			is_visited[i] = false;
			dist[i] = inf;
		}

		for (int i = 0; i < l; i++) {
			int a = io.getInt();
			int b = io.getInt();

			al[a].add(b);
			al[b].add(a);
		}

		for (int i = 0; i < c; i++) {
			if (!is_visited[i]) {
				findDiameter(i);
			}
		}

		int curr = diameters.peek();
		diameters.remove();

		while (!diameters.isEmpty()) {
			curr = Math.max(Math.max(curr, diameters.peek()), 
				(int)Math.ceil((double)curr / 2.0) + (int)Math.ceil((double)diameters.peek() / 2.0) + 1);
			diameters.remove();
		}

		io.println(curr);
		io.flush();
	}
}