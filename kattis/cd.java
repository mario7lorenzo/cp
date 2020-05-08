import java.util.*;

class CD {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in, System.out);
		while (true) {
			int n = io.getInt();
			int m = io.getInt();
			if (n == 0 && m == 0) {
				break;
			}
			HashSet<Integer> hs = new HashSet<Integer>();
			for (int i = 0; i < n; i++) {
				hs.add(io.getInt());
			}
			int counter = 0;
			for (int i = 0; i < m; i++) {
				if (hs.contains(io.getInt())) {
					counter++;
				}
			}
			io.println(counter);
		}
		io.flush();
	}
}