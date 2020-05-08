import java.util.*;

class Main {

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int tc = io.getInt();
		for (int t = 0; t < tc; t++) {
			int m = io.getInt();
			List<int[]> lst = new ArrayList<int[]>();
			List<Integer> heights = new ArrayList<Integer>();
			HashMap<Integer, Integer> total_width_counter = new HashMap<Integer, Integer>();
			TreeSet<Integer> total = new TreeSet<Integer>();
			
			for (int i = 0; i < m; i++) {
				int w = io.getInt();
				int h = io.getInt();
				lst.add(new int[]{w, h});
			}

			Collections.sort(lst, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[0] - b[0];
				}
			});
			
			Collections.sort(lst, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return b[1] - a[1];
				}
			});

			// Add the tallest dolls to the total pool
			// Claim: The tallest dolls do not need to be binary-searched since there is no taller doll
			// that can fit it.
			int counter = -1;
			int start_ind = -1;
			for (int i = 0; i < m; i++) {
				int curr_height = lst.get(i)[1];
				int curr_width = lst.get(i)[0];
				if (counter == -1 || counter == curr_height) {
					// add the width to the total pool
					total.add(curr_width);
					if (total_width_counter.containsKey(curr_width)) {
						total_width_counter.put(curr_width, total_width_counter.get(curr_width) + 1);
					} else {
						total_width_counter.put(curr_width, 1);
					}
					counter = curr_height;
					start_ind = i;
				} else {
					break;
				}
			}
			// Starting from the second tallest doll, iterate from the total pool to get the desired width
			// Claim: Anything in the total pool is strictly taller than the current doll. 
			start_ind++;
			int last_updated = start_ind;
			if (start_ind < m) {
				int curr_height = lst.get(start_ind)[1];
				for (int i = start_ind; i < m; i++) {
					int[] coor = lst.get(i);
					int curr_h = coor[1];
					int curr_width = coor[0];
					// If the current height is the same, we do not need to update the total pool and just do the binary searching
					// Else, we update the total pool by inserting all the same-tall dolls that we've just iterated
					if (curr_height != curr_h) {
						// Else, update the total pool by inserting all the previous width, starting from last_updated
						while (last_updated < i) {
							int width = lst.get(last_updated)[0];
							total.add(width);
							if (total_width_counter.containsKey(width)) {
								total_width_counter.put(width, total_width_counter.get(width) + 1);
							} else {
								total_width_counter.put(width, 1);
							}
							last_updated++;
						}
						curr_height = curr_h;
					}
					Integer good_width = total.higher(curr_width);
					// if there is no doll wider than it (can accomodate the width, good_width will be null)
					// if it's null, do nothing.
					if (good_width != null) {
						total_width_counter.put(good_width, total_width_counter.get(good_width) - 1);
						// If there is no such width left, delete from the total pool
						if (total_width_counter.get(good_width) == 0) {
							total.remove(good_width);
						}
					}
				}

				// We need to do one more iteration to update the total pool for the shortest dolls
				while (last_updated < m) {
					int width = lst.get(last_updated)[0];
					total.add(width);
					if (total_width_counter.containsKey(width)) {
						total_width_counter.put(width, total_width_counter.get(width) + 1);
					} else {
						total_width_counter.put(width, 1);
					}
					last_updated++;
				}
			}
			
			Iterator iterator = total.iterator();
			int result = 0;
			while (iterator.hasNext()) {
			    result += total_width_counter.get((int)iterator.next());
			}
			io.println(result);

		}
		io.flush();
	}	
}