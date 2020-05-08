import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);

		while (io.hasMoreTokens()) {
			Stack<Integer> stk = new Stack<>();
			Queue<Integer> q = new LinkedList<>();
			PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
			int n = io.getInt();

			boolean is_s = true;
			boolean is_q = true;
			boolean is_pq = true;

			for (int i = 0; i < n; i++) {
				int command = io.getInt();
				if (command == 1) {
					int x = io.getInt();
					stk.push(x);
					q.add(x);
					pq.add(x);
				} else {
					int x = io.getInt();
					if (stk.isEmpty()) {
						is_s = false;
					} else {
						if (stk.peek() != x) {
							is_s = false;
						}
						
						stk.pop();
					} 

					if (q.isEmpty()) {
						is_q = false;
					} else {
						if (q.peek() != x) {
							is_q = false;
						}
						q.remove();
					}

					if (pq.isEmpty()) {
						is_pq = false;
					} else {
						if (pq.peek() != x) {
							is_pq = false;
						}
						pq.remove();
					}
				}
			}

			int score = (is_s ? 1 : 0) + (is_q ? 1 : 0) + (is_pq ? 1 : 0);
			if (score == 0) {
				io.println("impossible");
			} else if (score == 1) {
				if (is_s) {
					io.println("stack");
				} else if (is_q) {
					io.println("queue");
				} else {
					io.println("priority queue");
				}
			} else {
				io.println("not sure");
			}
		}

		io.flush();
	}
}