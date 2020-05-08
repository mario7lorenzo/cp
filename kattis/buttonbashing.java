import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int inf = 1000000000;

		int tc = io.getInt();
		for (int k = 0; k < tc; k++) {
			int n = io.getInt();
			int t = io.getInt();

			ArrayList<Integer> buttons = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				buttons.add(io.getInt());
			}

			int[] time_dist = new int[3601];
			for (int i = 0; i <= 3600; i++) {
				time_dist[i] = inf;
			}

			time_dist[0] = 0;
			Queue<Integer> q = new LinkedList<>();

			q.add(0);

			while (!q.isEmpty()) {
				int x = q.peek();
				q.remove();

				for (int b : buttons) {
					int tot = x + b;
					if (tot < 0) {
						tot = 0;
					} else if (tot > 3600) {
						tot = 3600;
					}
					if (time_dist[tot] == inf) {
						time_dist[tot] = time_dist[x] + 1;
						q.add(tot);
					}
				}
			}

			for (int i = t; i <= 3600; i++) {
				if (time_dist[i] != inf) {
					io.println(time_dist[i] + " " + (i - t));
					break;
				}
			}
		}
		io.flush();
	}
}