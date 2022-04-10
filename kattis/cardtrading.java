import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int n = io.getInt();
		int t = io.getInt();
		int k = io.getInt();
		int singles = 0;

		HashMap<Integer, Integer> hmap = new HashMap<>();

		for (int i = 1; i <= t; i++) {
			hmap.put(i, 0);
		}

		for (int i = 0; i < n; i++) {
			int x = io.getInt();
			hmap.put(x, hmap.get(x) + 1);
		}
		ArrayList<Long> imaginarySellPrices = new ArrayList<>();

		long net = 0;

		for (int i = 1; i <= t; i++) {
			long a = io.getLong();
			long b = io.getLong();

			if (hmap.get(i) == 0) {
				net -= 2 * a;
				imaginarySellPrices.add(2*a);
			} else if (hmap.get(i) == 1) {
				net -= a;
				imaginarySellPrices.add(a+b);
			} else {
				imaginarySellPrices.add(2*b);
			}
		}

		Collections.sort(imaginarySellPrices, Collections.reverseOrder());

		for (int i = 0; i < t-k; i++) {
			net += imaginarySellPrices.get(i);
		}

		io.println(net);
		io.flush();
	}
}