import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int n, m;
		int counter = 0, pivot = 0;
		n = io.getInt();
		m = io.getInt();
		Queue<Integer> main_q = new LinkedList<>();
		Queue<Integer> rest_q = new LinkedList<>();
		Boolean[] arr = new Boolean[n + 1];

		for (int i = 0; i <= n; i++) {
			arr[i] = false;
		}

		for (int i = 0; i < m; i++) {
			int x = io.getInt();
			main_q.add(x);
			arr[x] = true;
		}

		for (int i = 1; i <= n; i++) {
			if (!arr[i]) {
				rest_q.add(i);
			}
		}

		while (counter < n) {
			if (main_q.size() == 0) {
				io.println(rest_q.peek());
				rest_q.remove();
			} else if (rest_q.size() == 0) {
				io.println(main_q.peek());
				main_q.remove();
			} else if (main_q.peek() < rest_q.peek()) {
				io.println(main_q.peek());
				main_q.remove();
			} else {
				io.println(rest_q.peek());
				rest_q.remove();
			}
			counter++;
		}

		io.flush();
	}
}