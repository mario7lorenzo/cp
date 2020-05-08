import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int n = io.getInt();
		long counter = 0;
		TreeMap<Long, Long> tmap = new TreeMap<Long, Long>();

		for (int i = 0; i < n; i++) {
			long x = io.getLong();
			if (i == 0) {
				tmap.put(x, 0L);
			}
			long depth_lb, depth_ub;
			Long lb = tmap.lowerKey(x);
			Long ub = tmap.higherKey(x);

			if ((Long)lb == null) {
				depth_lb = -1;
			} else {
				depth_lb = tmap.get(lb);

			}

			if ((Long)ub == null) {
				depth_ub = -1;
			} else {
				depth_ub = tmap.get(ub);
			}

			long depth = Math.max(depth_ub, depth_lb) + 1;
			tmap.put(x, depth);
			counter += depth;
			io.println(counter);
		}

		io.flush();
	}
}