import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		while (io.hasMoreTokens()) {
			int n = io.getInt();
			HashSet<Integer> hashmap = new HashSet<Integer>();
			int curr = io.getInt();
			for (int i = 0; i < n - 1; i++) {
				int x = io.getInt();
				if (Math.abs(curr - x) < n) {
					hashmap.add(Math.abs(curr - x));
				}
				curr = x;
			}
			if (hashmap.size() == n - 1) {
				io.println("Jolly");
			} else {
				io.println("Not jolly");
			}
		}
		io.flush();
	}
}