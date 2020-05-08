import java.util.*;

class Main {
	public static ArrayList<Integer>[] al = new ArrayList[1];
	public static ArrayList<Integer>[] transposed_al = new ArrayList[1];
	public static boolean[] is_enemy = new boolean[1];
	public static boolean[] is_visited = new boolean[1];
	public static int[] enemy_in_sccs = new int[1];
	public static Stack<Integer> stk = new Stack<>();
	public static int s = -1;
	public static HashSet<Integer>[] condensed_sccs = new HashSet[1];
	public static ArrayList<Integer>[] condensed_al = new ArrayList[1];
	public static ArrayList<Integer>[] condensed_transposed_al = new ArrayList[1];
	public static HashMap<Integer, Integer> which_sccs = new HashMap<>();
	public static int num_of_sccs = 0;
	public static boolean[] is_bad = new boolean[1];
	public static Kattio io = new Kattio(System.in);

	public static void kosaraju() {
		for (int i = 0; i < s; i++) {
			if (!is_visited[i]) {
				dfs(i);
			}
		} 

		for (int i = 0; i < s; i++) {
			is_visited[i] = false;
		}

		while (!stk.isEmpty()) {

			int val = (int)stk.pop();
			if (!is_visited[val]) {
				another_dfs(val);
				num_of_sccs++;
			}
		}
	}

	public static void dfs(int x) {
		is_visited[x] = true;

		for (int neighbor : al[x]) {
			if (!is_visited[neighbor]) {
				dfs(neighbor);
			}
		}
		stk.push(x);
	}

	public static void another_dfs(int x) {
		is_visited[x] = true;
		condensed_sccs[num_of_sccs].add(x);
		which_sccs.put(x, num_of_sccs);

		for (int neighbor : transposed_al[x]) {
			if (!is_visited[neighbor]) {
				another_dfs(neighbor);
			}
		}
	}

	public static void findBad(int x) {
		is_visited[x] = true;
		is_bad[x] = true;

		for (int neighbor : condensed_transposed_al[x]) {
			if (!is_visited[neighbor]) {
				findBad(neighbor);
			}
		}
	}

	public static void main(String[] args) {
		s = io.getInt();
		int e = io.getInt();
		int c = io.getInt();

		al = new ArrayList[s];
		transposed_al = new ArrayList[s];
		is_enemy = new boolean[s];
		condensed_sccs = new HashSet[s];
		is_visited = new boolean[s];

		for (int i = 0; i < s; i++) {
			al[i] = new ArrayList<>();
			transposed_al[i] = new ArrayList<>();
			is_enemy[i] = false;
			condensed_sccs[i] = new HashSet<>();
			is_visited[i] = false;
		}

		for (int i = 0; i < c; i++) {
			int a = io.getInt();
			int b = io.getInt();
			al[a].add(b);
			transposed_al[b].add(a);
		}

		for (int i = 0; i < e; i++) {
			is_enemy[io.getInt()] = true;
		}

		// Find the SCCs
		kosaraju();

		// Create the condensed SCC graph after running Kosaraju's
		condensed_al = new ArrayList[num_of_sccs];
		condensed_transposed_al = new ArrayList[num_of_sccs];
		enemy_in_sccs = new int[num_of_sccs];
		HashSet<Integer>[] already_added = new HashSet[num_of_sccs];
		is_bad = new boolean[num_of_sccs];
		int[] indegree = new int[num_of_sccs];

		for (int i = 0; i < num_of_sccs; i++) {
			condensed_al[i] = new ArrayList<>();
			condensed_transposed_al[i] = new ArrayList<>();
			already_added[i] = new HashSet<>();
			enemy_in_sccs[i] = 0;
			indegree[i] = 0;
			is_bad[i] = false;
		}

		for (int i = 0; i < s; i++) {
			int comp_1 = which_sccs.get(i);
			for (int neighbor : al[i]) {
				int comp_2 = which_sccs.get(neighbor);

				if (comp_1 != comp_2 && !already_added[comp_1].contains(comp_2)) {
					condensed_al[comp_1].add(comp_2);
					condensed_transposed_al[comp_2].add(comp_1);
					already_added[comp_1].add(comp_2);
					indegree[comp_2]++;
				}
			}

			if (is_enemy[i]) {
				enemy_in_sccs[comp_1]++;
				is_bad[comp_1] = true;
			}

			is_visited[i] = false;
		}

		// Check ALL possible SCC components that can reach the components that
		// contains spies, label them bad as well
		for (int i = 0; i < num_of_sccs; i++) {
			if (is_bad[i] && !is_visited[i]) {
				findBad(i);
			}
		}

		for (int i = 0; i < num_of_sccs; i++) {
			is_visited[i] = false;
		}

		for (int i = 0; i < num_of_sccs; i++) {
			if (is_bad[i]) {
				for (int neighbor : condensed_al[i]) {
					indegree[neighbor]--;
				}
			}
		}

		// If the component is bad, then ans += (total spies - enemies)
		// Otherwise, ans++ just for component with indegree 0
		int answer = 0;
		for (int i = 0; i < num_of_sccs; i++) {
			if (is_bad[i]) {
				answer += condensed_sccs[i].size() - enemy_in_sccs[i];
			} else if (indegree[i] == 0) {
				answer++;
			}
		}

		io.println(answer);
		io.flush();
	}
}