import java.util.*;

class Main {
	public static ArrayList<Integer>[] al = new ArrayList[1];
	public static long[] indegree = new long[1];
	public static long[] possible_path = new long[1];

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int n = io.getInt();
		int m = io.getInt();
		al = new ArrayList[n];
		indegree = new long[n];
		possible_path = new long[n];

		for (int i = 0; i < n; i++) {
			al[i] = new ArrayList<>();
			indegree[i] = 0;
			possible_path[i] = 0;
		}

		for (int i = 0; i < m; i++) {
			int x = io.getInt();
			int y = io.getInt();
			al[x].add(y);
			indegree[y]++;
		}

		Queue<Integer> q = new LinkedList<>();
		for (int i = 0; i < n; i++) {
			if (indegree[i] == 0) {
				q.add(i);
				possible_path[i] = 1;
			}
		}

		while (!q.isEmpty()) {
			int elem = q.peek();
			q.remove();

			for (int x : al[elem]) {
				possible_path[x] += possible_path[elem];
				indegree[x]--;

				if (indegree[x] == 0) {
					q.add(x);
				}
			}
		}

		HashSet<Integer> gates = new HashSet<>();
		int k = io.getInt();

		for (int i = 0; i < k; i++) {
			gates.add(io.getInt());
		}

		long total = 0;
		long win = 0;

		for (int i = 0; i < n; i++) {
			if (al[i].size() == 0) {
				total += possible_path[i];
				if (gates.contains(i)) {
					win += possible_path[i];
				}
			}
		}

		io.println("winning paths " + win);
		io.println("total paths " + total);
		io.flush();
	}
}