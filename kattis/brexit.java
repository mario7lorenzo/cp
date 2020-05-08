import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int c = io.getInt();
		int p = io.getInt();
		int x = io.getInt();
		int l = io.getInt();

		ArrayList<Integer>[] adj_lst = new ArrayList[c + 1];
		boolean[] still_alive = new boolean[c + 1];
		int[] neighbors = new int[c + 1];

		for (int i = 1; i <= c; i++) {
			ArrayList<Integer> al = new ArrayList<>();
			adj_lst[i] = al;
			still_alive[i] = true;
			neighbors[i] = 0;
		}

		for (int i = 0; i < p; i++) {
			int p1 = io.getInt();
			int p2 = io.getInt();
			adj_lst[p1].add(p2);
			adj_lst[p2].add(p1);
			neighbors[p1]++;
			neighbors[p2]++;
		}

		Queue<Integer> q = new LinkedList<>();
		still_alive[l] = false;

		for (int i : adj_lst[l]) {
			q.add(i);
			neighbors[i]--;
		}

		while(!q.isEmpty()) {
			int curr = q.peek();
			q.remove();
			if (still_alive[curr]) {
				if (neighbors[curr] <= adj_lst[curr].size() / 2) {
					still_alive[curr] = false;
					for (int i = 0; i < adj_lst[curr].size(); i++) {
						q.add(adj_lst[curr].get(i));
						neighbors[adj_lst[curr].get(i)]--;
					}
				}
			}
		}

		if (still_alive[x]) {
			io.println("stay");
		} else {
			io.println("leave");
		}

		io.flush();
	}
}