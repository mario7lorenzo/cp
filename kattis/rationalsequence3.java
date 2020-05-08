import java.util.*;

class Pair {
	public long first;
	public long second;

	public Pair(long first, long second) {
		this.first = first;
		this.second = second;
	}
}

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);

		int tc = io.getInt();

		while (tc-- > 0) {
			ArrayList<Integer> track = new ArrayList<>();
			int k = io.getInt();
			int n = io.getInt();

			while (n > 1) {
				if (n % 2 == 1) {
					n = (n - 1) / 2;
					track.add(n);
				} else {
					n = n / 2;
					track.add(n);
				}
			}

			Pair p = new Pair(1, 1);
			for (int i = track.size() - 1; i > 0; i--) {
				if (track.get(i) == track.get(i - 1) * 2) {
					p.second += p.first;
				} else {
					p.first += p.second;
				}
			}

			io.println(k + " " + p.first + "/" + p.second);
		}

		io.flush();
	}
}