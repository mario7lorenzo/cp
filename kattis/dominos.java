import java.util.*;

class Pair {
	public int first;
	public int second;

	public Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}
}



class Main {
	public static ArrayList<Integer>[] al = new ArrayList[1];
	public static ArrayList<Integer>[] transposed_al = new ArrayList[1];
	public static int[] parents = new int[1];
	public static boolean[] is_visited = new boolean[1];
	public static Stack<Integer> stk = new Stack<>();
	public static int[] store = new int[1];
	public static int n = -1;
	public static int m = -1;

	public static int find(int a) {
	    if (parents[a] == a) {
	        return a;
	    }

	    parents[a] = find(parents[a]);
	    return parents[a];
	}

	public static void join(int a, int b) {
	    a = find(a);
	    b = find(b);

	    if(a != b) {
	        parents[a] = b;
	    }
	}

	public static void kosaraju() {
		for (int i = 0; i < n; i++) {
			if (!is_visited[i]) {
				dfs(i);
			}
		}

		for (int i = 0; i < n; i++) {
			is_visited[i] = false;
		}

		while (!stk.isEmpty()) {
			int elem = stk.peek();
			stk.pop();
			another_dfs(elem);
		}
	}

	public static void dfs(int x) {
		is_visited[x] = true;

		for (int i : al[x]) {
			if (!is_visited[i]) {
				dfs(i);
			}
		}

		stk.push(x);
	}

	public static void another_dfs(int x) {
		is_visited[x] = true;

		for (int i : transposed_al[x]) {
			if (!is_visited[i]) {
				join(i, x);
				another_dfs(i);
			}
		}
	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int tc = io.getInt();

		while (tc-- > 0) {
			n = io.getInt();
			m = io.getInt();
			al = new ArrayList[n];
			transposed_al = new ArrayList[n];
			is_visited = new boolean[n];
			stk = new Stack<>();
			store = new int[n];
			ArrayList<Pair> arr = new ArrayList<>();
			parents = new int[n];

			for (int i = 0; i < n; i++) {
				al[i] = new ArrayList<>();
				transposed_al[i] = new ArrayList<>();
				is_visited[i] = false;
				parents[i] = i;
			}

			for (int i = 0; i < m; i++) {
				int u = io.getInt() - 1;
				int v = io.getInt() - 1;

				al[u].add(v);
				transposed_al[v].add(u);
				arr.add(new Pair(u, v));
			}

			kosaraju();

			for (int i = 0; i < n; i++) {
				store[parents[i]] = 0;
			}

			for (Pair p : arr) {
				if (parents[p.first] != parents[p.second]) {
					store[parents[p.second]]++;
				}
			}

			HashSet<Integer> hset = new HashSet<>();
			int total = 0;

			for (int i = 0; i < n; i++) {
				int ind = parents[i];
				if (store[ind] == 0 && !hset.contains(ind)) {
					hset.add(ind);
					total++;
				}
			}

			io.println(total);
		}

		io.flush();
	}
}