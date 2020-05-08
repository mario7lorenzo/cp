import java.util.*;

class Main {
	public static int[][] am = new int[1][1];
	public static ArrayList<Integer>[] al = new ArrayList[1];
	public static int n = -1;
	public static boolean[] is_visited = new boolean[1];
	public static Stack<Integer> stk = new Stack<>();

	public static void topoSort() {
		for (int i = 0; i < n; i++) {
			if (!is_visited[i]) {
				dfs(i);
			}
		}
	}

	public static void dfs(int x) {
		is_visited[x] = true;
		for (int i : al[x]) {
			if (!is_visited[i]) {
				dfs(i);
			}
		}

		stk.add(x);
	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		n = io.getInt();
		int k = io.getInt();
		am = new int[n][n];
		is_visited = new boolean[n];
		al = new ArrayList[n];

		for (int i = 0; i < n; i++) {
			al[i] = new ArrayList<>();
			for (int j = 0; j < n; j++) {
				am[i][j] = 0;
			}
			is_visited[i] = false;
		}

		for (int i = 0; i < k; i++) {
			int a = io.getInt();
			int b = io.getInt();

			am[a][b] = 1;
			al[a].add(b);
		}

		topoSort();
		Object[] arr = stk.toArray();
		boolean is_unique = true;
		for (int i = 1; i < n; i++)	{
			if (am[(int)arr[i]][(int)arr[i - 1]] == 0) {
				is_unique = false;
				break;
			}
		}

		if (!is_unique) {
			io.println("back to the lab");
		} else {
			for (int i = n-1; i >= 0; i--) {
				if (i == n-1) {
					io.print((int)arr[i]);
				} else {
					io.print(" " + (int)arr[i]);
				}
			}
			io.println();
		}
		io.flush();
	}
}