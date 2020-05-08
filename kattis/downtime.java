import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int n = io.getInt();
		int k = io.getInt();
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();

		int server = 0;

		for (int i = 0; i < n; i++) {
			int finish_time = io.getInt();

			if (!pq.isEmpty()) {
				if (pq.peek() <= finish_time) {
					pq.poll();
				}
			}

			pq.add(finish_time + 1000);
			if (server * k < pq.size()) {
				server++;
			}
		}
		io.println(server);
		io.flush();
	}
}