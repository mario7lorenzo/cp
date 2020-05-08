import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int tc = io.getInt();

		while (tc-- > 0) {
			int n = io.getInt();
			HashSet<String> hset = new HashSet<>();

			for (int i = 0; i < n; i++) {
				hset.add(io.getWord());
			}

			io.println(hset.size());
		}

		io.flush();
	}
}