import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int q = io.getInt();
		HashMap<Integer, PriorityQueue<Integer>> energy_pool = new HashMap<Integer, PriorityQueue<Integer>>();
		TreeSet<Integer> tset = new TreeSet<Integer>();

		for (int i = 0; i < q; i++) {
			String command = io.getWord();
			if (command.equals("add")) {
				int e = io.getInt();
				int g = io.getInt();
				if (!energy_pool.containsKey(e)) {
					energy_pool.put(e, new PriorityQueue<Integer>());
				}
				energy_pool.get(e).add(-g);
				tset.add(e);
			} else {
				int x = io.getInt();
				long total_gold = 0;
				while ((Integer)tset.lower(x + 1) != null) {
					int smaller_equal = tset.lower(x + 1);
					total_gold -= energy_pool.get(smaller_equal).poll();
					if (energy_pool.get(smaller_equal).isEmpty()) {
						tset.remove(smaller_equal);
					}
					x -= smaller_equal;
				}
				io.println(total_gold);
			}
		}
		io.flush();
	}
}