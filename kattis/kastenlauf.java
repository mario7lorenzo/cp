import java.util.*;

class Pair {
	public int x;
	public int y;

	public Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int tc = io.getInt();

		for (int k = 0; k < tc; k++) {
			int n = io.getInt();

			Pair[] lst = new Pair[n + 2];

			boolean[] is_visited = new boolean[n + 2];

			for (int i = 0; i < n + 2; i++) {
				lst[i] = new Pair(io.getInt(), io.getInt());
				is_visited[i] = false;
			}

			Queue<Integer> q = new LinkedList<>();
			q.add(0);
			is_visited[0] = true;

			while (!q.isEmpty()) {
				int x = q.peek();
				q.remove();
				Pair curr_coor = lst[x];

				for (int i = 0; i < n + 2; i++) {
					if (!is_visited[i]) {
						Pair dest_coor = lst[i];
						int dist = Math.abs(curr_coor.x - dest_coor.x) + Math.abs(curr_coor.y - dest_coor.y);
						if (dist <= 1000) {
							q.add(i);
							is_visited[i] = true;
						}
					}
				}
			}

			if (is_visited[n + 1]) {
				io.println("happy");
			} else {
				io.println("sad");
			}
		}

		io.flush();
	}
}